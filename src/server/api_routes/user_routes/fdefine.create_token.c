//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *create_token_route() {


    cJSON *login_json = cJSON_GetObjectItemCaseSensitive(global_body_json, "login");
    if(login_json == NULL || login_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_LOGIN, MISSING_LOGIN_MSG);
    }
    char *login = login_json->valuestring;
    DtwResource *user = find_user_by_email_or_name(login);
    if(user == NULL){
        return create_response_msg(NOT_FOUND, USER_NOT_FOUND, USER_NOT_FOUND_MSG);
    }
    cJSON *password_json = cJSON_GetObjectItemCaseSensitive(global_body_json, PASSWORD_ENTRIE);
    if(password_json == NULL || password_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_PASSWORD, PASSWORD_NOT_PROVIDED);
    }
    char *password = password_json->valuestring;
    char *user_password =DtwResource_get_string_from_sub_resource(user, PASSWORD_PATH);
    char *transformed_password = transform_password(password);
    if(strcmp(user_password, transformed_password) != 0){
        return create_response_msg(FORBIDDEN, PASSWORD_NOT_MATCH, PASSWORD_NOT_MATCH_MSG);
    }
    char *token = create_user_token(user);
    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json,TOKEN_RESPONSE, token);
      return cweb_send_cJSON_cleaning_memory(json, OK);


}