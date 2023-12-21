#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
    this->init();
}

AnimationComponent::~AnimationComponent()
{
    this->destroy();
}

void AnimationComponent::init()
{
    this->m_index = Vector2{0, 0};
    this->m_frame = 0;
    this->m_frame_counter = 0;
    this->m_frame_speed = 0;

    this->m_is_playing = false;
}

void AnimationComponent::update()
{
    if (this->m_is_playing)
    {
        this->m_frame_counter++;
        if (this->m_frame_counter >= this->m_frame_speed)
        {
            this->m_frame++;

            this->m_index.x = this->m_current_animation->getFrom().x + this->m_frame;
            this->m_index.y = this->m_current_animation->getFrom().y;

            if (this->m_index.x > this->m_current_animation->getTo().x)
            {
                this->m_index.x = this->m_current_animation->getFrom().x;
                this->m_index.y++;
            }

            if (this->m_frame >= this->m_current_animation->getNumberOfFrames())
            {
                this->m_frame = 0;
            }
            this->m_frame_counter = 0;
        }
    }
}

void AnimationComponent::destroy()
{
}

void AnimationComponent::setAnimation(std::string animation_name, Animation animation)
{
    this->m_animations[animation_name] = animation;
}

void AnimationComponent::playAnimation(std::string animation_name)
{
    this->m_current_animation = &this->m_animations[animation_name];
    this->m_frame = 0;
    this->m_frame_counter = 0;
    this->m_frame_speed = 1;
    this->m_is_playing = true;

    this->m_source_rectangle.x = this->m_index.x * this->m_current_animation->getWidth();
    this->m_source_rectangle.y = this->m_index.y * this->m_current_animation->getHeight();

    this->m_source_rectangle.width = this->m_current_animation->getWidth();
    this->m_source_rectangle.height = this->m_current_animation->getHeight();
}