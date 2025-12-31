PROJECT_NAME = "Quill"
CONTANIZER   = darwin.argv.get_flag_arg_by_index({ "provider", "contanizer" }, 1, "podman")
VERSION      = "0.1.0"
LICENSE      = "MIT"
URL          = "https://github.com/mateusmoutinho/Quill"
DESCRIPITION = "Quill - C-Based Blog Engine"
FULLNAME     = "Mateus Moutinho"
EMAIL        = "mateusmoutinho01@gmail.com"
SUMARY       = "Quill - C-Based Blog Engine"
LANGUAGE     = "c"

-- Load all build recipes from builds/ directory
darwin.load_all("builds")