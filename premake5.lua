workspace "souleater"
    configurations { "Debug", "Release" }
    startproject "souleater"

project "souleater"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("bin-int/%{cfg.buildcfg}")

    files
    {
        "src/**.cpp",
        "src/**.h",
        "vendor/raygui/src/**.h",
        "vendor/raygui/src/**.c",
        "vendor/rres/src/**.h",
        "vendor/rres/src/**.c",
    }

    includedirs {
        "vendor/raylib/src",
        "vendor/raylib/src/external",
        "vendor/raylib/src/external/glfw/include",
        "vendor/raygui/src",
        "vendor/rres/src",
        "vendor/rres/src/external",
        "vendor/yaml-cpp/include",
    }

    links {
        "raylib",
        "yaml-cpp"
    }

    filter {"system:macosx"}
        links {
            "Cocoa.framework",
            "IOKit.framework",
            "CoreVideo.framework",
        }
    
    filter{}

    include "vendor/deps_premake5.lua"
        
    os.writefile_ifnotequal("#define RAYGUI_IMPLEMENTATION\n#include <raygui.h>", "vendor/raygui/src/raygui.c")
    os.writefile_ifnotequal("#pragma warning(disable : 4996)\n#include <raylib.h>\n#define RRES_IMPLEMENTATION\n#include <rres.h>\n#define RRES_RAYLIB_IMPLEMENTATION\n#include <rres-raylib.h>", "vendor/rres/src/rres.c")

