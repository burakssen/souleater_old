#pragma once

#include <raylib.h>

#include "../Component.h"
#include "../TransformComponent/TransformComponent.h"

class TextureComponent : public Component
{
public:
    TextureComponent();
    ~TextureComponent();

    virtual void init() override;
    void draw() override;
    virtual void update() override;
    virtual void destroy() override;

    void setTexture(Texture2D *texture);
    Texture2D getTexture();

    void setSourceRectangle(Rectangle source_rectangle);
    Rectangle getSourceRectangle();

protected:
    Texture2D *m_texture;
    Rectangle m_source_rectangle;
};