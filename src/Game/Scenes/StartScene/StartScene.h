#pragma once

#include <raygui.h>

#include "../../../SceneManager/Scene/Scene.h"
#include "../../../SceneManager/SceneManager.h"

#include "../../../Log/Log.h"

class StartScene : public Scene
{
public:
    StartScene();
    ~StartScene();

    void init() override;
    void draw() override;
    void update() override;
    void destroy() override;

private:
    bool start_button_pressed = false;
    bool exit_button_pressed = false;

    Rectangle start_button;
    Rectangle exit_button;

    Texture2D background;

    Font font;

    SceneManager *scene_manager = nullptr;
};