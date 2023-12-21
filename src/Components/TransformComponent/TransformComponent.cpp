#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
    this->init();
}

TransformComponent::~TransformComponent()
{
    this->destroy();
}

void TransformComponent::init()
{
    this->m_position = Vector2Zero();
    this->m_rotation = 0.0f;
    this->m_scale = Vector2One();
}

void TransformComponent::update()
{
}

void TransformComponent::destroy()
{
}

void TransformComponent::setPosition(Vector2 position)
{
    this->m_position = position;
}

Vector2 TransformComponent::getPosition()
{
    return this->m_position;
}

void TransformComponent::setRotation(float rotation)
{
    this->m_rotation = rotation;
}

float TransformComponent::getRotation()
{
    return this->m_rotation;
}

void TransformComponent::setScale(Vector2 scale)
{
    this->m_scale = scale;
}

Vector2 TransformComponent::getScale()
{
    return this->m_scale;
}
