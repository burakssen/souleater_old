#pragma once

#include <map>

#include <raylib.h>

#include "../TextureComponent/TextureComponent.h"
#include "../../ResourceManager/Resource/AnimatedTextureResource/AnimatedTextureResource.h"

class AnimationComponent : public TextureComponent
{
public:
    AnimationComponent();
    ~AnimationComponent();

    void init() override;
    void update() override;
    void destroy() override;
    void setAnimation(std::string animation_name, Animation animation);
    void playAnimation(std::string animation_name);

private:
    Vector2 m_index = {0, 0};
    std::map<std::string, Animation> m_animations;

    int m_frame = 0;
    int m_frame_counter = 0;
    float m_frame_speed = 10;
    bool m_is_playing = true;

    Animation *m_current_animation = nullptr;
};