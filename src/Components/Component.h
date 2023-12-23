#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #include <Rpc.h>
    typedef UUID uuid_t;
#else
    #include <uuid/uuid.h>
#endif

#include <string>

#include "../Entities/Entity.h"

class Entity;

class Component
{
public:
    Component();
    ~Component();

    virtual void init();
    virtual void draw();
    virtual void update();
    virtual void destroy();
    virtual void handleEvents();

    void setEntity(Entity *entity);
    Entity *getEntity();

    const uuid_t &getId();

protected:
    Entity *m_entity;

private:
    uuid_t m_id;
};
