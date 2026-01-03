#include "imports/imports.dep_define.h"

int main(int argc, char *argv[]) {
  CArgvParse args = newCArgvParse(argc, argv);
  const char *action = CArgvParse_get_arg(&args, 1);

  if (action == NULL) {
    printf("No action provided\n");
    return 1;
  }

  if (strcmp(action, START_SERVER) == 0) {
    return start_server_cli(&args);
  }
  printf("Unknown action: %s\n", action);
  return 0;
}