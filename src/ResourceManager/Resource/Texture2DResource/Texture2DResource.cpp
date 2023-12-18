//
// Created by burak şen on 14.12.2023.
//

#include "Texture2DResource.h"

Texture2DResource::Texture2DResource()
{
    this->init();
}

Texture2DResource::~Texture2DResource()
{
    this->destroy();
}

void Texture2DResource::init()
{
    this->m_texture2d = nullptr;
    this->m_resource_type = ResourceType::Texture2D;
}

void Texture2DResource::destroy()
{
    UnloadTexture(*this->m_texture2d);
}

Texture2D* Texture2DResource::getTexture2D()
{
    if (this->m_texture2d != nullptr)
        return this->m_texture2d;

    Image img = LoadImageFromResource(*this->m_resource_chunk);
    this->m_texture2d = new Texture2D();
    *this->m_texture2d = LoadTextureFromImage(img);
    return this->m_texture2d;
}

void Texture2DResource::setTexture2D(Texture2D *texture2d)
{
    this->m_texture2d = texture2d;
}
