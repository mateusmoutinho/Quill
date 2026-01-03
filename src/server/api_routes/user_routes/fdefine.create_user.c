//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end

CwebHttpResponse *create_user_route() {


    cJSON *username_json = cJSON_GetObjectItemCaseSensitive(global_body_json, "username");
    if(username_json == NULL || username_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_USERNAME, USERNAME_NOT_PROVIDED);
    }
    char *username = username_json->valuestring;

    cJSON *email_json = cJSON_GetObjectItemCaseSensitive(global_body_json, "email");
    if(email_json == NULL || email_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_EMAIL, EMAIL_NOT_PROVIDED);
    }
    char *email = email_json->valuestring;

    cJSON *password_json = cJSON_GetObjectItemCaseSensitive(global_body_json, "password");
    if(password_json == NULL || password_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_PASSWORD, PASSWORD_NOT_PROVIDED);
    }
    char *password = password_json->valuestring;

    
    long user_type = AUTHOR_TYPE;
  
    cJSON *user_type_json = cJSON_GetObjectItemCaseSensitive(global_body_json, USER_TYPE_ENTRIE);
    if(user_type_json != NULL && user_type_json->valuestring != NULL){
        char *user_type_str = user_type_json->valuestring;
        
        if(strcmp(user_type_str, AUTHOR_TYPE_STR) == 0){
            user_type = AUTHOR_TYPE;
        }
        else if(strcmp(user_type_str, PUBLISHER_TYPE_STR) == 0){
            user_type = PUBLISHER_TYPE;
        }
        else if(strcmp(user_type_str, ROOT_TYPE_STR) == 0){
            user_type = ROOT_TYPE;
        }
        else {
            return create_response_msg(BAD_REQUEST, INVALID_USER_TYPE, INVALID_USER_TYPE_MSG);
        }
    }
  
    DtwResource *possible_existent_user = find_user_by_email_or_name(email);
    if(
        possible_existent_user != NULL){
        return create_response_msg(BAD_REQUEST, USER_ALREADY_EXISTS, USER_ALREADY_EXISTS_MSG);
    }

    possible_existent_user = find_user_by_email_or_name(username);
    if(
        possible_existent_user != NULL){
        return create_response_msg(BAD_REQUEST, USER_ALREADY_EXISTS, USER_ALREADY_EXISTS_MSG);
    }

    create_user_database(username, email, password, user_type);
    DtwResource_commit(global_database);
    return create_response_msg(OK, SUCESS_CODE, "User created");
}