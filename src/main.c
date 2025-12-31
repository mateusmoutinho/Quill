#include "imports/imports.dep_define.h"
#include <string.h>

int main(int argc, char *argv[]) {
  CArgvParse args = newCArgvParse(argc, argv);
  const char *action = CArgvParse_get_arg(&args, 1);

  if (action == NULL) {
    printf("No action provided\n");
    return 1;
  }

  if (strcmp(action, START_SERVER) == 0) {
    const char *root_password = CArgvParse_get_flag(
        (&args), ROOT_PASSWORD_FLAGS, ROOT_PASSWORD_FLAGS_SIZE, 0);

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
    return 0;
  }
  printf("Unknown action: %s\n", action);
  return 0;
}