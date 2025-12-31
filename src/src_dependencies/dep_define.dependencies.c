
#ifdef DEFINE_DEPENDENCIES
#include "../../dependencies/CArgvParse.c"

#include "../../dependencies/CTextEngine.c"
#include "../../dependencies/CWebStudio.c"
#include "../../dependencies/doTheWorldOne.c"

#define error LuaCembedError
#include "../../dependencies/LuaCEmbed.c"
#undef error
#include "../../dependencies/UniversalGarbage.c"
#include "../../dependencies/UniversalSocket.c"
#endif