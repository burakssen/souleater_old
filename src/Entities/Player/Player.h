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
    void update() override;
    void draw() override;
    void destroy() override;

private:
    Shader shader;
};