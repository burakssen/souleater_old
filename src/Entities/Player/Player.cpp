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
    this->m_shader = LoadShader(0, "resources/shaders/fragment_shader.fs");
}

void Player::draw()
{
    BeginShaderMode(this->m_shader);
    Entity::draw();
    // DrawRectangle(0, 0, 100, 100, RED);
    EndShaderMode();
}

void Player::handleEvents()
{
    TransformComponent *transform_component = this->getComponent<TransformComponent>();
    AnimationComponent *animation_component = this->getComponent<AnimationComponent>();
    if (transform_component == nullptr)
        return;

    if(!IsKeyDown(KEY_S) && !IsKeyDown(KEY_W))
    {
        Log::info("IDLE");
        transform_component->setPosition(Vector2{transform_component->getPosition().x, transform_component->getPosition().y});
        if(animation_component)
            animation_component->playAnimation("IDLE");

        return;
    }

    if (IsKeyDown(KEY_W) && IsKeyUp(KEY_S))
    {
        Log::info("WALK_UP");
        transform_component->setPosition(Vector2{transform_component->getPosition().x, transform_component->getPosition().y - 1});
        if(animation_component)
            animation_component->playAnimation("WALK_UP");
    }
    
    if (IsKeyDown(KEY_S) && IsKeyUp(KEY_W))
    {
        Log::info("WALK_DOWN");
        transform_component->setPosition(Vector2{transform_component->getPosition().x, transform_component->getPosition().y + 1});
        if(animation_component)
            animation_component->playAnimation("WALK_DOWN");
    }

}
