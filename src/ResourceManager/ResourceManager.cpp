#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    this->init();
}

ResourceManager::~ResourceManager()
{
    this->destroy();
}

void ResourceManager::init()
{
    this->m_central_dir = rresLoadCentralDirectory(GAMEDATA_PATH);
    int metadata_index = rresGetResourceId(this->m_central_dir, "metadata.yaml");
    rresResourceChunk metadata_chunk = rresLoadResourceChunk(GAMEDATA_PATH, metadata_index);
    std::string meta = LoadTextFromResource(metadata_chunk);
    rresUnloadResourceChunk(metadata_chunk);

    YAML::Node metadata = YAML::Load(meta);
    this->m_resources_node = metadata["resources"];
}

void ResourceManager::destroy()
{
    rresUnloadCentralDirectory(this->m_central_dir);
}

void ResourceManager::loadResources()
{
    for (auto resource : this->m_resources_node)
    {
        this->generateResource(resource);
    }
}

void ResourceManager::generateResource(const YAML::Node &resource_node)
{
    auto resource_name = resource_node["name"].as<std::string>();
    auto resource_type = resource_node["resourceType"].as<std::string>();
    auto resource_path = resource_node["resourcePath"].as<std::string>();

    if (resource_type == "Texture2D")
    {
        std::cout << "Loading Texture2D: " << resource_name << std::endl;
        int resource_id = rresGetResourceId(this->m_central_dir, resource_path.c_str());
        std::cout << "Resource ID: " << resource_id << std::endl;
        rresResourceChunk resource_chunk = rresLoadResourceChunk(GAMEDATA_PATH, resource_id);
        Image image = LoadImageFromResource(resource_chunk);
        auto *texture = new Texture2D();
        *texture = LoadTextureFromImage(image);
        UnloadImage(image);
        rresUnloadResourceChunk(resource_chunk);

        if (resource_node["textureType"].IsDefined())
        {
            auto texture_type = resource_node["textureType"].as<std::string>();
            if (texture_type == "AnimatedTexture")
            {
                auto *texture_resource = new AnimatedTextureResource();
                texture_resource->setNumberOfAnimations(resource_node["numberOfAnimations"].as<int>());
                for (auto ani : resource_node["animations"])
                {
                    Animation animation;
                    animation.setNumberOfFrames(ani["numberOfFrames"].as<int>());
                    animation.setWidth(ani["width"].as<int>());
                    animation.setHeight(ani["height"].as<int>());
                    animation.setFrom(Vector2{ani["from"]["x"].as<float>(), ani["from"]["y"].as<float>()});
                    animation.setTo(Vector2{ani["to"]["x"].as<float>(), ani["to"]["y"].as<float>()});
                    animation.setType((AnimationType)ani["type"].as<int>());
                    texture_resource->addAnimation(ani["name"].as<std::string>(), animation);
                }
                texture_resource->setTexture2D(texture);
                this->m_resources[resource_name] = texture_resource;
                return;
            }
        }

        auto *texture_resource = new Texture2DResource();
        texture_resource->setTexture2D(texture);
        this->m_resources[resource_name] = texture_resource;
        return;
    }

    Log::error("Resource type not found: " + resource_type);
}

Resource *ResourceManager::getResource(const std::string &resource_name)
{
    return this->m_resources[resource_name];
}