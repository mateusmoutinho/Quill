

function create_objects_linkage()
    local compiler = "gcc"
    if LAUNGUAGE == "cpp" then
        compiler = "g++"
    end
    os.execute("mkdir -p libs")
    local itens = {

        {command=compiler.." -shared -fPIC dependencies/CArgvParse.c -o libs/CArgvParse.so",out_path="libs/CArgvParse.so"},
        {command=compiler.." -shared -fPIC dependencies/CTextEngine.c -o libs/CTextEngine.so",out_path="libs/CTextEngine.so"},
        {command=compiler.." -shared -fPIC dependencies/UniversalGarbage.c -o libs/UniversalGarbage.so",out_path="libs/UniversalGarbage.so"},
        {command=compiler.." -shared -fPIC dependencies/cJSON.c -o libs/cJSON.so",out_path="libs/cJSON.so"},
        {command=compiler.." -shared -fPIC dependencies/UniversalSocket.c -o libs/UniversalSocket.so",out_path="libs/UniversalSocket.so"},
        {command=compiler.." -shared -fPIC dependencies/LuaCEmbed.c    -o libs/LuaCEmbed.so",out_path="libs/LuaCEmbed.so"},
        {command=compiler.." -shared -fPIC dependencies/CWebStudio.c       -o libs/CWebStudio.so",out_path="libs/CWebStudio.so"},
        {command=compiler..[[ -shared -fPIC dependencies/doTheWorldOne.c     -DDTW_CHASH_PATH=\"CHashManipulator.c\"  -DDTW_ALLOW_CHASH  -o libs/doTheWorld.so]],out_path="libs/doTheWorld.so"},

    }

    for _, item in ipairs(itens) do
        
            os.execute(item.command)
    end


end 



darwin.add_recipe({
    name = "libs_so",
    inputs = {
        "dependencies"
    },
    description = "Build shared libraries and link them locally",
    outs = {
        "libs/CArgvParse.so",
        "libs/CTextEngine.so", 
        "libs/UniversalGarbage.so",
        "libs/cJSON.so",
        "libs/UniversalSocket.so",
        "libs/LuaCEmbed.so",
        "libs/CWebStudio.so",
        "libs/doTheWorld.so"
    },
    callback = create_objects_linkage
})