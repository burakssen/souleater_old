#pragma once

#include "../Resource.h"

#include <raylib.h>
#include <rres-raylib.h>

class Texture2DResource : public Resource {

public:
    Texture2DResource();
    ~Texture2DResource();

    void init() override;
    void destroy() override;

    Texture2D* getTexture2D();

    void setTexture2D(Texture2D *texture2d);

private:
    Texture2D* m_texture2d = nullptr;
protected:
    ResourceType m_resource_type = ResourceType::Texture2D;
};
