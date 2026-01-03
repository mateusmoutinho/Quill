//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end

CwebHttpResponse *main_server(CwebHttpRequest *request) {
  start_database();
  if (dtw_starts_with(request->route, API_START)) {
    return main_api_handler(request);
  }
  if (dtw_starts_with(request->route, ADMIN_START)) {
    return cweb_send_text("admin area", 200);
  }

  return cweb_send_text("execution area", 200);
}


int  start_server_cli(CArgvParse *args) {
     const char *root_password = CArgvParse_get_flag((args), ROOT_PASSWORD_FLAGS, ROOT_PASSWORD_FLAGS_SIZE, 0);

    if (root_password == NULL) {
      printf("No (--%s) password provided\n", ROOT_PASSWORD_FLAGS[0]);
      return 1;
    }

    printf("Root password: %s\n", root_password);
    if (strlen(root_password) > sizeof(global_root_password)) {
      printf("Root password too long\n");
      return 1;
    }
    strcpy(global_root_password, root_password);
    printf("Root password set to: %s\n", global_root_password);

    const char *database_path = CArgvParse_get_flag((args), DATABASE_PATH_FLAGS, DATABASE_PATH_FLAGS_SIZE, 0);

    if (database_path == NULL) {
      database_path = "data";
    }
    if (strlen(database_path) > sizeof(global_database_path)) {
      printf("Database path too long\n");
      return 1;
    }
    strcpy(global_database_path, database_path);
    printf("Database path set to: %s\n", global_database_path);

    CwebServer server = newCwebSever(5000, main_server);
    CwebServer_start(&server);

    return 0;
}