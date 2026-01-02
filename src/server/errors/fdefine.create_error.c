//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


CwebHttpResponse *create_error(int status_code, int error_code, const char *msg,
                               ...) {

  va_list args;
  va_start(args, msg);
  char *formmated = private_dtw_format_vaarg(msg, args);
  va_end(args);
  cJSON *response = cJSON_CreateObject();
  cJSON_AddStringToObject(response, "message", formmated);
  free(formmated);
  cJSON_AddNumberToObject(response, "status_code", status_code);
  return cweb_send_cJSON_cleaning_memory(response, status_code);
}