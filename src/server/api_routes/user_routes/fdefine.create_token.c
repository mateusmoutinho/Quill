//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *create_token_route() {
   
    const char *login = get_json_string_from_object(global_body_json, LOGIN_ENTRIE);
    GLOBAL_ERROR_PROTECT_NULL
    const char *password = get_json_string_from_object(global_body_json, PASSWORD_ENTRIE);
    GLOBAL_ERROR_PROTECT_NULL

    long expiration = get_json_long_from_object(global_body_json, EXPIRATION_ENTRIE);
    GLOBAL_ERROR_PROTECT_ZERO
    if(expiration < 0){
        expiration = -1;
    }
    DtwResource *user = find_user_by_email_or_name(login);
    GLOBAL_ERROR_PROTECT_NULL

    if(user == NULL){
        return create_response_msg(BAD_REQUEST, USER_NOT_FOUND, USER_NOT_FOUND_MSG);
    }

    long expiration_value = expiration;
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