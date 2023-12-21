#pragma once

#include <raylib.h>
#include <raymath.h>

#include "../Component.h"

class TransformComponent : public Component
{
public:
    TransformComponent();
    ~TransformComponent();

    void init() override;
    void update() override;
    void destroy() override;

    void setPosition(Vector2 position);
    Vector2 getPosition();

    void setRotation(float rotation);
    float getRotation();

    void setScale(Vector2 scale);
    Vector2 getScale();

private:
    Vector2 m_position;
    float m_rotation;
    Vector2 m_scale;
};