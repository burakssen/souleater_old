#pragma once

#include <raygui.h>

#include "../../../Entities/Player/Player.h"

#include "../../../SceneManager/Scene/Scene.h"

#include "../../../Log/Log.h"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();

    void init() override;
    void draw() override;
    void update() override;
    void destroy() override;

private:
    Texture2D background;
    Font font;

    std::vector<Entity *> m_entities;
};