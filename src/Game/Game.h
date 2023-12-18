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
    int window_width = 1024;
    int window_height = 720;

    std::string window_title = "Soul Eater";
    std::string version = "0.0.1";

    bool button_pressed = false;

    SceneManager *scene_manager = nullptr;
    ResourceManager *resource_manager = nullptr;
    Texture2D *texture = nullptr;
};