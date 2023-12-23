-- premake5.lua
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
        "src/raygui/**.h",
        "src/raygui/**.c",
        "src/rres/**.h",
        "src/rres/**.c",
    }

    -- Dependencies
    raylib_version = "5.0"
    raylib_dir = _WORKING_DIR .. "/vendor/raylib" -- Set this to the actual path of your raylib installation

    yamlcpp_version = "0.8.0"
    yamlcpp_dir = _WORKING_DIR .. "/vendor/yaml-cpp" -- Set this to the actual path of your yaml-cpp installation

    rres_version = "1.2.0"
    rres_dir = _WORKING_DIR .. "/vendor/rres" -- Set this to the actual path of your rres installation

    -- Use raylib as an external dependency
    if not os.isdir(raylib_dir) then
        -- Fetch and build raylib if not found
        print("Fetching and building raylib...")
        os.execute("git clone --branch " .. raylib_version .. " --depth 1 https://github.com/raysan5/raylib " .. raylib_dir)
        os.chdir(raylib_dir .. "/src")
        os.execute("make -j8") -- Adjust the build command based on your platform
        os.chdir("../../")
    end

    -- Use yaml-cpp as an external dependency
    if not os.isdir(yamlcpp_dir) then
        print("Fetching and building yaml-cpp...")
        os.execute("git clone --branch " .. yamlcpp_version .. " --depth 1 https://github.com/jbeder/yaml-cpp " .. yamlcpp_dir)
        os.chdir(yamlcpp_dir)
        os.execute("mkdir build && cd build && cmake .. && make -j8") -- Adjust the build command based on your platform
        os.chdir("../")
    end

    -- Use rres as an external dependency
    if not os.isdir(rres_dir) then
        print("Fetching and building rres...")
        os.execute("git clone --branch " .. rres_version .. " --depth 1 https://github.com/raysan5/rres " .. rres_dir)
        os.chdir(rres_dir)
        -- os.execute("mkdir build && cd build && cmake .. && make -j8") -- Adjust the build command based on your platform
        -- os.chdir("../")
        os.rename(rres_dir .. "/src/", _WORKING_DIR .. "/src/rres")
        os.writefile_ifnotequal("#pragma warning(disable : 4996)\n#include <raylib.h>\n#define RRES_IMPLEMENTATION\n#include <rres.h>\n#define RRES_RAYLIB_IMPLEMENTATION\n#include <rres-raylib.h>",  _WORKING_DIR .. "/src/rres/rres.c")        
        

        -- Copy necessary files and create rres.c
    end

    -- Fetch raygui.h if not found
    if not os.isfile(_WORKING_DIR .. "/src/raygui/raygui.h") then
        print("Fetching raygui.h...")
        os.mkdir(_WORKING_DIR .. "/src/raygui")
        os.execute("curl -L https://raw.githubusercontent.com/raysan5/raygui/master/src/raygui.h -o " .. _WORKING_DIR .. "/src/raygui/raygui.h")
        os.touchfile(_WORKING_DIR .. "/src/raygui/raygui.c")
        os.writefile_ifnotequal("#define RAYGUI_IMPLEMENTATION\n#include <raygui.h>", _WORKING_DIR .. "/src/raygui/raygui.c")        
    end

    includedirs
    {
        raylib_dir .. "/src",
        yamlcpp_dir .. "/include",
        _WORKING_DIR .. "/src/rres",
        _WORKING_DIR .. "/src/raygui",
        _WORKING_DIR .. "/src/**/*",
    }

    libdirs
    {
        raylib_dir .. "/src",
        yamlcpp_dir .. "/build"

    }

    links
    {
        "raylib",
        "yaml-cpp",
    }

    -- Project configurations
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    -- Additional configurations based on platform
    filter "system:macosx"
        links { "Cocoa.framework", "IOKit.framework", "OpenGL.framework" }

    -- Copy resources to output directory
    filter {}
    files
    {
        "resources/**",
    }

    postbuildcommands
    {
        -- Copy resources to output directory after build
        "{COPY} resources %{cfg.targetdir}",
  
    }

    -- Custom target for running the executable
    newaction {
        trigger = "run",
        description = "Running souleater",
        execute = function()
            os.execute(_WORKING_DIR .. "/bin/Debug/" .. project().name)
        end
    }
