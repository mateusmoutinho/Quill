//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *main_api_handler(CwebHttpRequest *request) {


  if(strcmp(request->route,CREATE_USER)==0){
    return create_user_route(request);
  }

  if(strcmp(request->route,REMOVE_USER)==0){
    return remove_user_route(request);
  }

  if(body_json){
    cJSON_Delete(body_json);
  }
  return create_response_msg(NOT_FOUND, UNDEFINED_ROUTE_CODE, UNDEFINED_ROUTE,
                      request->route);
}