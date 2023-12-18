#pragma once

#include <string>
#include <raylib.h>

#include <rres-raylib.h>

enum class ResourceType
{
    Texture2D,
    AnimatedTexture,
    Font,
    Sound,
    Image,
    Text,
    Unkown
};

class Resource
{
public:
    Resource();
    ~Resource();

    Resource(const Resource &) = delete;
    Resource &operator=(const Resource &) = delete;

    virtual void init();
    virtual void destroy();

protected:
    rresResourceChunk *m_resource_chunk;
    ResourceType m_resource_type = ResourceType::Unkown;

private:
    std::string m_resource_name;
};