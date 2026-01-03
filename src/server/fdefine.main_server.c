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

    const char *salt = CArgvParse_get_flag((args), SALT_FLAGS, SALT_FLAGS_SIZE, 0);

    if (salt == NULL) {
      printf("No (--%s) provided\n", SALT_FLAGS[0]);
      return 1;
    }

    if (strlen(salt) > sizeof(global_salt)) {
      printf("Salt too long\n");
      return 1;
    }
    strcpy(global_salt, salt);
    printf("Salt set to: %s\n", global_salt);

    const char *port_str = CArgvParse_get_flag((args), PORT_FLAGS, PORT_FLAGS_SIZE, 0);

    if (port_str == NULL) {
      printf("No (--%s) provided\n", PORT_FLAGS[0]);
      return 1;
    }

    global_port = atoi(port_str);
    if (global_port <= 0 || global_port > 65535) {
      printf("Invalid port number: %s (must be between 1 and 65535)\n", port_str);
      return 1;
    }
    printf("Port set to: %d\n", global_port);

    CwebServer server = newCwebSever(global_port, main_server);
    CwebServer_start(&server);

    return 0;
}