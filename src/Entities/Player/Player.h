#pragma once

#include "../Entity.h"

#include "../../Components/AnimationComponent/AnimationComponent.h"
#include "../../Components/TransformComponent/TransformComponent.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    void init() override;
    void draw() override;
    void handleEvents() override;

private:
    Shader m_shader;
};