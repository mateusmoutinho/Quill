//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end

CwebHttpResponse *create_user_route(CwebHttpRequest *request) {

    CwebHttpResponse *error = read_body_json(request, 1024);
    if(error != NULL){
        return error;
    }

    cJSON *username_json = cJSON_GetObjectItemCaseSensitive(body_json, "username");
    if(username_json == NULL || username_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_USERNAME, USERNAME_NOT_PROVIDED);
    }
    char *username = username_json->valuestring;

    cJSON *email_json = cJSON_GetObjectItemCaseSensitive(body_json, "email");
    if(email_json == NULL || email_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_EMAIL, EMAIL_NOT_PROVIDED);
    }
    char *email = email_json->valuestring;

    cJSON *password_json = cJSON_GetObjectItemCaseSensitive(body_json, "password");
    if(password_json == NULL || password_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_PASSWORD, PASSWORD_NOT_PROVIDED);
    }
    char *password = password_json->valuestring;

    bool is_root = false;
    cJSON *is_root_json = cJSON_GetObjectItemCaseSensitive(body_json, "is_root");
    if(is_root_json != NULL){
        is_root = is_root_json->valueint;
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

    create_user_database(username, email, password,is_root);
    DtwResource_commit(global_database);
    return create_response_msg(SUCESS_CODE, SUCESS_CODE, "User created");
}