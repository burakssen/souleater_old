//
// Created by burak şen on 18.12.2023.
//

#include "AnimatedTextureResource.h"

Animation::Animation()
{
    this->init();
}

Animation::~Animation()
{
    this->destroy();
}

void Animation::init()
{
    this->m_number_of_frames = 0;
    this->m_width = 0;
    this->m_height = 0;
    this->m_from = {0, 0};
    this->m_to = {0, 0};
    this->m_type = AnimationType::Loop;
}

void Animation::destroy()
{
}

void Animation::setNumberOfFrames(int number_of_frames)
{
    this->m_number_of_frames = number_of_frames;
}

void Animation::setWidth(int width)
{
    this->m_width = width;
}

void Animation::setHeight(int height)
{
    this->m_height = height;
}

void Animation::setFrom(Vector2 from)
{
    this->m_from = from;
}

void Animation::setTo(Vector2 to)
{
    this->m_to = to;
}

void Animation::setType(AnimationType type)
{
    this->m_type = type;
}

int Animation::getNumberOfFrames()
{
    return this->m_number_of_frames;
}

int Animation::getWidth()
{
    return this->m_width;
}

int Animation::getHeight()
{
    return this->m_height;
}

Vector2 Animation::getFrom()
{
    return this->m_from;
}

Vector2 Animation::getTo()
{
    return this->m_to;
}

AnimationType Animation::getType()
{
    return this->m_type;
}

AnimatedTextureResource::AnimatedTextureResource()
{
    this->init();
}

AnimatedTextureResource::~AnimatedTextureResource()
{
    this->destroy();
}

void AnimatedTextureResource::init()
{
    this->m_number_of_animations = 0;
    this->m_resource_type = ResourceType::AnimatedTexture;
}

void AnimatedTextureResource::destroy()
{
    for (auto &animation : this->m_animations)
    {
        animation.second.destroy();
    }
}

void AnimatedTextureResource::setNumberOfAnimations(int number_of_animations)
{
    this->m_number_of_animations = number_of_animations;
}

void AnimatedTextureResource::addAnimation(const std::string &animation_name, Animation animation)
{
    this->m_animations[animation_name] = animation;
}

int AnimatedTextureResource::getNumberOfAnimations()
{
    return this->m_number_of_animations;
}

Animation AnimatedTextureResource::getAnimation(const std::string &animation_name)
{
    return this->m_animations[animation_name];
}

std::map<std::string, Animation> AnimatedTextureResource::getAnimations()
{
    return this->m_animations;
}