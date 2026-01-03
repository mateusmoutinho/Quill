//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep_declare.h"
//silver_chain_scope_end


const char *START_SERVER = "start_server";
const char *ROOT_PASSWORD_FLAGS[] = {
    "root_password",
};
const int ROOT_PASSWORD_FLAGS_SIZE =
    sizeof(ROOT_PASSWORD_FLAGS) / sizeof(ROOT_PASSWORD_FLAGS[0]);

const char *DATABASE_PATH_FLAGS[] = {
    "database_path",
};
const int DATABASE_PATH_FLAGS_SIZE =
    sizeof(DATABASE_PATH_FLAGS) / sizeof(DATABASE_PATH_FLAGS[0]);

const char *SALT_FLAGS[] = {
    "salt",
};
const int SALT_FLAGS_SIZE =
    sizeof(SALT_FLAGS) / sizeof(SALT_FLAGS[0]);

const char *PORT_FLAGS[] = {
    "port",
};
const int PORT_FLAGS_SIZE =
    sizeof(PORT_FLAGS) / sizeof(PORT_FLAGS[0]);
