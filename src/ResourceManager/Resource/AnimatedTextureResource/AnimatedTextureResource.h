#pragma once

#include <map>

#include "../Texture2DResource/Texture2DResource.h"

enum class AnimationType
{
    Loop,
    PingPong,
    Once
};

class Animation
{

public:
    Animation();
    ~Animation();

    void init();
    void destroy();

    void setNumberOfFrames(int number_of_frames);
    void setWidth(int width);
    void setHeight(int height);
    void setFrom(Vector2 from);
    void setTo(Vector2 to);
    void setType(AnimationType type);
    void addAnimation(const std::string &animation_name, Rectangle animation);

    int getNumberOfFrames();
    int getWidth();
    int getHeight();
    Vector2 getFrom();
    Vector2 getTo();
    AnimationType getType();
    Rectangle getAnimation(const std::string &animation_name);

private:
    int m_number_of_frames;
    int m_width;
    int m_height;
    Vector2 m_from;
    Vector2 m_to;
    AnimationType m_type;
    std::map<std::string, Rectangle> m_animation_list;
};

class AnimatedTextureResource : public Texture2DResource
{
public:
    AnimatedTextureResource();
    ~AnimatedTextureResource();

    void init() override;
    void destroy() override;

    void setNumberOfAnimations(int number_of_animations);
    void addAnimation(const std::string &animation_name, Animation animation);

    int getNumberOfAnimations();
    Animation getAnimation(const std::string &animation_name);

private:
    int m_number_of_animations;
    std::map<std::string, Animation> m_animations;
};
