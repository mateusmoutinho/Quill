//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse * read_body_json(CwebHttpRequest *request,int max_size) {
   
    const char *body = (const char*)CwebHttpRequest_read_content(request, max_size);
    if(body == NULL){
        return create_response_msg(BAD_REQUEST, BODY_NOT_PROVIDED_CODE, BODY_NOT_PROVIDED, "body not provided"); 
    }
   global_body_json = cJSON_Parse(body);
    if(global_body_json == NULL){
        return create_response_msg(BAD_REQUEST, BODY_NOT_JSON_CODE, BODY_NOT_JSON, "body is not a json"); 
    }
    return NULL;
}


CwebHttpResponse *main_api_handler() {
  CwebHttpResponse *response = NULL;
  
  for(int i = 0; i < sizeof(API_ROUTES)/sizeof(API_ROUTES[0]); i++){
    Route current_route = API_ROUTES[i];
    if(strcmp(global_request->route, current_route.route) == 0){

      if(current_route.requires_body_json){    
        CwebHttpResponse *error = read_body_json(global_request, current_route.max_body_size);
          if(error != NULL){
              response =  error;
          }
      }    
      if(response == NULL){
          response = current_route.handler();
      }
    }
  }

  if(global_body_json){
    cJSON_Delete(global_body_json);
  }
  if(response == NULL){
    return create_response_msg(NOT_FOUND, UNDEFINED_ROUTE_CODE, UNDEFINED_ROUTE,global_request->route);
  }
  return response;
}