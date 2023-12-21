#include "Component.h"

Component::Component()
{
    this->init();
}

Component::~Component()
{
    this->destroy();
}

void Component::init()
{
    uuid_generate(this->m_id);
}

void Component::draw()
{
}

void Component::update()
{
}

void Component::destroy()
{
}

void Component::setEntity(Entity *entity)
{
    this->m_entity = entity;
}

Entity *Component::getEntity()
{
    return this->m_entity;
}

const uuid_t &Component::getId()
{
    return this->m_id;
}

void Component::handleEvents()
{
}