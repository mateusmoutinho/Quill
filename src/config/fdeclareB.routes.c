//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end


const char *API_START = "/api";
const char *ADMIN_START = "/admin";

typedef struct Route{
    const char *route;
    CwebHttpResponse *(*handler)();
    bool requires_body_json;
    int max_body_size;
    int requred_acess;
}Route;

Route API_ROUTES[] = {
    {.route="/api/create_user", .handler= create_user_route, .requires_body_json=true, .max_body_size=1024, .requred_acess=ROOT_TYPE},
    {.route="/api/remove_user", .handler= remove_user_route, .requires_body_json=true, .max_body_size=1024, .requred_acess=ROOT_TYPE},
    {.route="/api/create_token", .handler= create_token_route, .requires_body_json=true, .max_body_size=1024, .requred_acess=PUBLIC_TYPE},
};