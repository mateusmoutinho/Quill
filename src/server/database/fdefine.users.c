//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end
void destroy_user(DtwResource *user){
    DtwResource_destroy(user);
}
char *transform_password(const char *password){
    char * password_concatened_with_salt = malloc(sizeof(global_salt)+40);
    strcpy(password_concatened_with_salt, global_salt);
    strcat(password_concatened_with_salt, password);
    char *result = dtw_generate_sha_from_string(password_concatened_with_salt);
    free(password_concatened_with_salt);
    return result;
}

void create_user_database(const char * name, const char * email, const char * password,long user_type){
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *user = DtwResource_new_schema_insertion(users);
    DtwResource_set_string_in_sub_resource(user, NAME_PATH, name);
    DtwResource_set_string_in_sub_resource(user, EMAIL_PATH, email);
    DtwResource_set_long_in_sub_resource(user, USER_TYPE_PATH, user_type);
    char *user_sha = transform_password(password);
    DtwResource_set_string_in_sub_resource(user, PASSWORD_PATH, user_sha);

    DtwResource_commit(global_database);

    free(user_sha);

}

DtwResource *find_user_by_name(const char *name) {
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *found_user = DtwResource_find_by_primary_key_with_string(users, "name", name);
    return found_user;
}

DtwResource *find_user_by_email(const char *email) {
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *found_user = DtwResource_find_by_primary_key_with_string(users, "email", email);
    return found_user;
}


DtwResource *find_user_by_email_or_name(const char *email_or_name) {
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *found_user = DtwResource_find_by_primary_key_with_string(users, "email", email_or_name);
    if (found_user == NULL) {
        found_user = DtwResource_find_by_primary_key_with_string(users, "name", email_or_name);
    }
    return found_user;
}


DtwResource *find_user_by_id(const char *id) {
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *found_user = DtwResource_find_by_name_id(users, id);
    return found_user;
}   

char *create_user_token(DtwResource *user){



    char *user_name  = DtwResource_get_string_from_sub_resource(user, NAME_PATH);
    char *user_password = DtwResource_get_string_from_sub_resource(user, PASSWORD_PATH);




    DtwResource *tokens_database = DtwResource_sub_resource(user, TOKEN_PATH);
    DtwDatabaseSchema *token_root_schema =  DtwResource_newDatabaseSchema(tokens_database);
    DtwDtatabaseSchema_new_subSchema(token_root_schema,TOKEN_PATH);
    DtwResource *tokens = DtwResource_sub_resource(tokens_database, TOKEN_PATH);    


    DtwResource *created_token = DtwResource_new_schema_insertion(tokens);
    if(DtwResource_error(global_database)){
        printf("error: %s\n",DtwResource_get_error_message(global_database));
    }
  

    long now = time(NULL);
    DtwResource_set_long_in_sub_resource(created_token,CREATION_PATH, now);



    char required_informations[300] ={0};
    sprintf(required_informations, "%s%s%ld%s", user_name, user_password, now, global_salt);
    char *token_password = dtw_generate_sha_from_string(required_informations);
    DtwResource_set_string_in_sub_resource(created_token,TOKEN_PASSWORD, token_password);
    DtwResource_commit(global_database);



    char *complete_token = malloc(100 + strlen(token_password));


    printf("alocou o token\n");
    printf("name: %s\n", user->name);
    printf("token password: %s\n", token_password);

    sprintf(complete_token, "%s.%s.%s", user->name,created_token->name, token_password);
    printf("criou o token\n");
    free(token_password);
    return complete_token;
}