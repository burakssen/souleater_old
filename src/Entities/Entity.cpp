#include "Entity.h"

Entity::Entity()
{
    this->init();
}

Entity::~Entity()
{
    this->destroy();
}

void Entity::init()
{
    this->m_resource_manager = &ResourceManager::getInstance();
}

void Entity::update()
{
    this->handleEvents();
    for (auto component : m_components)
    {
        component->update();
    }
}

void Entity::draw()
{
    for (auto component : m_components)
    {
        component->draw();
    }
}

void Entity::destroy()
{
    for (auto component : m_components)
    {
        component->destroy();
        delete component;
    }
    m_components.clear();
}

void Entity::handleEvents()
{
    for (auto component : m_components)
    {
        component->handleEvents();
    }
}