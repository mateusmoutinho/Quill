//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end



cJSON *get_object_from_path(cJSON *object,const char *key){
     cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
     if(!value){
         global_error = create_response_msg(BAD_REQUEST, KEY_NOT_FOUND, KEY_NOT_FOUND_MSG,key);
         return NULL;
     }
     
     return value;
}

long get_json_long_from_object(cJSON *object,const char *key){
     cJSON *value = get_object_from_path(object,key);
     GLOBAL_ERROR_PROTECT_ZERO
     if(!cJSON_IsNumber(value)){
        global_error = create_response_msg(BAD_REQUEST, KEY_WRONG_TYPE, KEY_WRONG_TYPE_MSG,key,"integer");
        return 0;
     }
     return value->valueint;
}


long get_json_long_from_object_or_default(cJSON *object,const char *key,long default_value){
    cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
    if(!value){
        return default_value;
    }
    return get_json_long_from_object(object,key);
}

const char *get_json_string_from_object(cJSON *object,const char *key){
     cJSON *value = get_object_from_path(object,key);
     GLOBAL_ERROR_PROTECT_NULL
     if(!cJSON_IsString(value)){
        global_error = create_response_msg(BAD_REQUEST, KEY_WRONG_TYPE, KEY_WRONG_TYPE_MSG,key,"string");
        return NULL;
     }
     return value->valuestring;
}

const char *get_json_string_from_object_or_default(cJSON *object,const char *key,char *default_value){
    cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
    if(!value){
        return default_value;
    }
    return get_json_string_from_object(object,key);
}

bool get_json_bool_from_object(cJSON *object,const char *key){
     cJSON *value = get_object_from_path(object,key);
     GLOBAL_ERROR_PROTECT_ZERO
     if(!cJSON_IsBool(value)){
        global_error = create_response_msg(BAD_REQUEST, KEY_WRONG_TYPE, KEY_WRONG_TYPE_MSG,key,"boolean");
        return false;
     }
     return cJSON_IsTrue(value);
}

bool get_json_bool_from_object_or_default(cJSON *object,const char *key,bool default_value){
    cJSON *value = cJSON_GetObjectItemCaseSensitive(object,key);
    if(!value){
        return default_value;
    }
    return get_json_bool_from_object(object,key);
}