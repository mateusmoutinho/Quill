//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *remove_user_route(CwebHttpRequest *request) {

    CwebHttpResponse *error = read_body_json(request, 1024);
    if(error != NULL){
        return error;
    }

    cJSON *login_json = cJSON_GetObjectItemCaseSensitive(body_json, "login");
    if(login_json == NULL || login_json->valuestring == NULL){
        return create_response_msg(BAD_REQUEST, MISSING_LOGIN, MISSING_LOGIN_MSG);
    }
    char *login = login_json->valuestring;
    
    DtwResource *possible_existent_user = find_user_by_email_or_name(login);
    if(
        possible_existent_user == NULL){
        return create_response_msg(BAD_REQUEST, USER_NOT_FOUND, USER_NOT_FOUND_MSG);
    }
    destroy_user(possible_existent_user);
    DtwResource_commit(global_database);
    return create_response_msg(OK,SUCESS_CODE, "User removed");

   
}