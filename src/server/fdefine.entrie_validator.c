//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end



cJSON *get_object_from_path(cJSON *object,const char *path,const char *key){
     cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
     if(!value){
         global_error = create_response_msg(BAD_REQUEST, KEY_NOT_FOUND, KEY_NOT_FOUND_MSG,key,path);
         return NULL;
     }
     
     return value;
}

long get_json_long_from_object(cJSON *object,const char *path,const char *key){
     cJSON *value = get_object_from_path(object,path,key);
     GLOBAL_ERROR_PROTECT_ZERO
     if(!cJSON_IsNumber(value)){
        global_error = create_response_msg(BAD_REQUEST, KEY_WRONG_TYPE, KEY_WRONG_TYPE_MSG,key,path,"boolean");
        return 0;
     }
     return value->valueint;
}
        

long get_json_long_from_object_or_default(cJSON *object,const char *path,const char *key,long default_value){
    cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
    if(!value){
        return default_value;
    }
    return get_json_long_from_object(object,path,key);
}