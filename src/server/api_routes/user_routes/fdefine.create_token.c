//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *create_token_route() {


   
    char *login = get_json_string_from_object(global_body_json,LOGIN_JSON_PATH, LOGIN_ENTRIE);
    GLOBAL_ERROR_PROTECT_NULL
    char *password = get_json_string_from_object(global_body_json, PASSWORD_JSON_PATH, PASSWORD_ENTRIE);
    GLOBAL_ERROR_PROTECT_NULL

    long expiration = get_json_long_from_object(global_body_json, EXPIRATION_JSON_PATH, EXPIRATION_ENTRIE);
    GLOBAL_ERROR_PROTECT_ZERO
    if(expiration < 0){
        return create_response_msg(BAD_REQUEST, EXPIRATION_NOT_PROVIDED, EXPIRATION_NOT_PROVIDED_MSG);
    }

    
    long expiration_value = expiration;
    char *password = password_json->valuestring;
    char *user_password =DtwResource_get_string_from_sub_resource(user, PASSWORD_PATH);
    char *transformed_password = transform_password(password);
    if(strcmp(user_password, transformed_password) != 0){
        return create_response_msg(FORBIDDEN, PASSWORD_NOT_MATCH, PASSWORD_NOT_MATCH_MSG);
    }
    char *token = create_user_token(user,expiration_value);
    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json,TOKEN_RESPONSE, token);
      return cweb_send_cJSON_cleaning_memory(json, OK);


}