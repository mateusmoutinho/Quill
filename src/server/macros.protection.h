//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep_declare.h"
//silver_chain_scope_end

#define GLOBAL_ERROR_PROTECT_ZERO  if(global_error || DtwResource_error(global_database)){return 0;}
#define GLOBAL_ERROR_PROTECT_NULL if(global_error || DtwResource_error(global_database)){return NULL;}
