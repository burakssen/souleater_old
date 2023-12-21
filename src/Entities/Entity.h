#pragma once

#include <string>
#include <vector>

#include <raylib.h>

#include "../Components/Component.h"

#include "../ResourceManager/ResourceManager.h"

class Component;

class Entity
{
public:
    Entity();
    ~Entity();

    virtual void init();
    virtual void update();
    virtual void draw();
    virtual void destroy();
    virtual void handleEvents();

    template <typename T>
    T *addComponent()
    {
        T *component = new T();
        component->setEntity(this);
        m_components.push_back(component);
        return component;
    }

    template <typename T>
    T *getComponent()
    {
        for (auto component : m_components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t != nullptr)
            {
                return t;
            }
        }
        return nullptr;
    }

    template <typename T>
    void removeComponent()
    {
        for (auto component : m_components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t != nullptr)
            {
                m_components.erase(std::remove(m_components.begin(), m_components.end(), t), m_components.end());
                delete t;
                return;
            }
        }
    }

    template <typename T>
    bool hasComponent()
    {
        for (auto component : m_components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t != nullptr)
            {
                return true;
            }
        }
        return false;
    }

protected:
    ResourceManager *m_resource_manager = nullptr;

private:
    std::vector<Component *> m_components;
};