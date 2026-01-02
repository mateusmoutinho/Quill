//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end

CwebHttpResponse *create_user_route(CwebHttpRequest *request) {

    CwebHttpResponse *error = read_body_json(request, 1024);
    if(error != NULL){
        return error;
    }

    char *username = cJSON_GetObjectItemCaseSensitive(body_json, "username")->valuestring;
    if( username == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_USERNAME, USERNAME_NOT_PROVIDED);
    }

    char *email = cJSON_GetObjectItemCaseSensitive(body_json, "email")->valuestring;
    if(email == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_EMAIL, EMAIL_NOT_PROVIDED);
    }
    char *password = cJSON_GetObjectItemCaseSensitive(body_json, "password")->valuestring;
    if(password == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_PASSWORD, PASSWORD_NOT_PROVIDED);
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

    create_user_database(username, email, password);
    DtwResource_commit(global_database);
    return create_response_msg(SUCESS_CODE, SUCESS_CODE, "User created");
}