// silver_chain_scope_start
// mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
// silver_chain_scope_end

CwebHttpResponse *main_server(CwebHttpRequest *request) {
  if (dtw_starts_with(request->route, API_START)) {
    return cweb_send_text("api area", 200);
  }
  if (dtw_starts_with(request->route, ADMIN_START)) {
    return cweb_send_text("admin area", 200);
  }

  return cweb_send_text("execution area", 200);
}