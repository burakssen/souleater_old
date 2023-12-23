#pragma once

#include <raygui.h>

#include <rres-raylib.h>

#include <iostream>

#include "../Log/Log.h"

#include "../SceneManager/SceneManager.h"
#include "Scenes/StartScene/StartScene.h"
#include "Scenes/GameScene/GameScene.h"
#include "Scenes/LoadingScene/LoadingScene.h"

#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/Resource/Texture2DResource/Texture2DResource.h"

class Game
{
private:
    Game();
    ~Game();

public:
    static Game &GetInstance();
    void run();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    Game(Game &&) = delete;

    void init();
    void draw();
    void update();
    void destroy();

private:
    int m_window_width = 1024;
    int m_window_height = 720;

    std::string m_window_title = "Soul Eater";
    std::string m_version = "0.0.1";

    bool m_button_pressed = false;

    SceneManager *m_scene_manager = nullptr;
    ResourceManager *m_resource_manager = nullptr;
};