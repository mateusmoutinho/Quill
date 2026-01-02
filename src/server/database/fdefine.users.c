//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


DtwResource *find_user_by_name(const char *name) {

    DtwResource *users = DtwResource_sub_resource(global_database, USERS_PATH);
    DtwResource *found_user = DtwResource_find_by_primary_key_with_string(users, "name", name);
    
    return found_user;
}
