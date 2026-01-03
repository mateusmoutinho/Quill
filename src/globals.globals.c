//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.fdeclareB.h"
//silver_chain_scope_end

char global_root_password[40] = {0};
char global_database_path[256] = {0};
char global_salt[64] = {0};
int global_port = 0;
cJSON *global_body_json = NULL;
DtwResource *global_database;
CwebHttpRequest *global_request;