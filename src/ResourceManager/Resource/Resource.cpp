#include "Resource.h"

Resource::Resource()
{
    this->init();
}

Resource::~Resource()
{
    this->destroy();
}

void Resource::init()
{
    this->m_resource_chunk = nullptr;
    this->m_resource_name = "";
}

void Resource::destroy()
{
    if(this->m_resource_chunk != nullptr)
        delete this->m_resource_chunk;
}