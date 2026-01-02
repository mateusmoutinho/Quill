//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse * read_body_json(CwebHttpRequest *request,int max_size) {
   
    const char *body = (const char*)CwebHttpRequest_read_content(request, max_size);
    if(body == NULL){
        return create_response_msg(BAD_REQUEST, BODY_NOT_PROVIDED_CODE, BODY_NOT_PROVIDED, "body not provided"); 
    }
   body_json = cJSON_Parse(body);
    if(body_json == NULL){
        return create_response_msg(BAD_REQUEST, BODY_NOT_JSON_CODE, BODY_NOT_JSON, "body is not a json"); 
    }
    return NULL;
}