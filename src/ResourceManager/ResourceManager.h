#pragma once

#include <string>
#include <map>

#include <raygui.h>
#include <rres-raylib.h>

#include <yaml-cpp/yaml.h>

#include "Resource/Resource.h"
#include "Resource/Texture2DResource/Texture2DResource.h"
#include "Resource/AnimatedTextureResource/AnimatedTextureResource.h"
#include "../Log/Log.h"

#define GAMEDATA_PATH "resources/gamedata.bin"

class ResourceManager
{
private:
    ResourceManager();
    ~ResourceManager();

public:
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    static ResourceManager &getInstance()
    {
        static ResourceManager instance;
        return instance;
    }

    void init();
    void destroy();
    void loadResources();
    void generateResource(const YAML::Node &resource_node);
    Resource *getResource(const std::string &resource_name);

private:
    std::map<std::string, Resource *> m_resources;
    int m_resource_count = 0;
    YAML::Node m_resources_node;
    rresCentralDir m_central_dir;
};
