// silver_chain_scope_start
// mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
// silver_chain_scope_end

CwebHttpResponse *main_server(CwebHttpRequest *request) {

  return cweb_send_text("Hello World", 200);
}