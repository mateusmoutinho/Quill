//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *remove_user_route() {

    const char *login = get_json_string_from_object(global_body_json, LOGIN_ENTRIE);
    GLOBAL_ERROR_PROTECT_NULL
    
    DtwResource *possible_existent_user = find_user_by_email_or_name(login);
    if(
        possible_existent_user == NULL){
        return create_response_msg(BAD_REQUEST, USER_NOT_FOUND, USER_NOT_FOUND_MSG);
    }
    destroy_user(possible_existent_user);
    DtwResource_commit(global_database);
    return create_response_msg(OK,SUCESS_CODE, "User removed");

   
}