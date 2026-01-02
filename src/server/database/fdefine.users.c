//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end

void create_user_database(const char * name, const char * email, const char * password){
    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *user = DtwResource_new_schema_insertion(users);
    DtwResource_set_string_in_sub_resource(user, NAME_PATH, name);
    DtwResource_set_string_in_sub_resource(user, EMAIL_PATH, email);
    DtwResource_set_string_sha_in_sub_resource(user, PASSWORD_PATH, password);
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