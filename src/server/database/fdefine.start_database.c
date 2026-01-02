//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


void start_database() {
  global_database = new_DtwResource(global_database_path);

  DtwDatabaseSchema *root_schema =
      DtwResource_newDatabaseSchema(global_database);
  // Define a sub-schema for users
  DtwSchema *users_schema =
      DtwDtatabaseSchema_new_subSchema(root_schema, USERS_PATH);

  // Set primary keys for unique identification
  DtwSchema_add_primary_key(users_schema, NAME_PATH);
  DtwSchema_add_primary_key(users_schema, EMAIL_PATH);
}