//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end

CwebHttpResponse *create_user_route() {


    const char *username = get_json_string_from_object(global_body_json, "username");
    GLOBAL_ERROR_PROTECT_NULL

    const char *email = get_json_string_from_object(global_body_json, "email");
    GLOBAL_ERROR_PROTECT_NULL

    const char *password = get_json_string_from_object(global_body_json, "password");
    GLOBAL_ERROR_PROTECT_NULL

    long user_type = AUTHOR_TYPE;
  
    const char *user_type_str = get_json_string_from_object(global_body_json, USER_TYPE_ENTRIE);
    if(user_type_str != NULL){
        
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
    GLOBAL_ERROR_PROTECT_NULL
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
    GLOBAL_ERROR_PROTECT_NULL
    return create_response_msg(OK, SUCESS_CODE, "User created");
}