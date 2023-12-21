#include "Player.h"

Player::Player()
{
    this->init();
}

Player::~Player()
{
    this->destroy();
}

void Player::init()
{
    TransformComponent *transform_component = this->addComponent<TransformComponent>();
    AnimationComponent *animation_component = this->addComponent<AnimationComponent>();
    AnimatedTextureResource *animation_resource = static_cast<AnimatedTextureResource *>(this->m_resource_manager->getResource("player"));
    if (animation_resource != nullptr)
    {
        animation_component->setTexture(animation_resource->getTexture2D());
        for (auto animation : animation_resource->getAnimations())
        {
            animation_component->setAnimation(animation.first.c_str(), animation.second);
        }
    }

    transform_component->setPosition(Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2});
    transform_component->setRotation(0);
    transform_component->setScale(Vector2{5, 5});
    animation_component->playAnimation("IDLE");
    this->shader = LoadShader(0, "resources/shaders/fragment_shader.fs");
}

void Player::draw()
{
    BeginShaderMode(this->shader);
    Entity::draw();
    // DrawRectangle(0, 0, 100, 100, RED);
    EndShaderMode();
}

void Player::update()
{
    this->getComponent<TextureComponent>()->update();
}

void Player::destroy()
{
    this->getComponent<TextureComponent>()->destroy();
}
