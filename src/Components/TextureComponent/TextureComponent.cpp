#include "TextureComponent.h"

TextureComponent::TextureComponent()
{
    this->init();
}

TextureComponent::~TextureComponent()
{
    this->destroy();
}

void TextureComponent::init()
{
    this->m_texture = nullptr;
    this->m_source_rectangle = Rectangle{0, 0, 0, 0};
}

void TextureComponent::draw()
{
    if (this->m_texture != nullptr)
    {
        if (this->m_entity->hasComponent<TransformComponent>())
        {
            TransformComponent *transformComponent = this->m_entity->getComponent<TransformComponent>();
            // DrawTextureEx(*this->m_texture, transformComponent->getPosition(), transformComponent->getRotation(), transformComponent->getScale().x, WHITE);
            Rectangle source_rectangle = this->m_source_rectangle;
            if (source_rectangle.width == 0 && source_rectangle.height == 0)
            {
                source_rectangle.width = this->m_texture->width;
                source_rectangle.height = this->m_texture->height;
            }

            Rectangle destination_rectangle = Rectangle{transformComponent->getPosition().x, transformComponent->getPosition().y, source_rectangle.width * transformComponent->getScale().x, source_rectangle.height * transformComponent->getScale().y};
            DrawTexturePro(*this->m_texture, source_rectangle, destination_rectangle, Vector2{0, 0}, transformComponent->getRotation(), WHITE);
        }
        else
        {
            DrawTexture(*this->m_texture, 0, 0, WHITE);
        }
    }
}

void TextureComponent::update()
{
}

void TextureComponent::destroy()
{
    if (this->m_texture != nullptr)
    {
        this->m_texture = nullptr;
    }
}

void TextureComponent::setTexture(Texture2D *texture)
{
    this->m_texture = texture;
}

Texture2D TextureComponent::getTexture()
{
    return *this->m_texture;
}

void TextureComponent::setSourceRectangle(Rectangle source_rectangle)
{
    this->m_source_rectangle = source_rectangle;
}

Rectangle TextureComponent::getSourceRectangle()
{
    return this->m_source_rectangle;
}