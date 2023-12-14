#pragma once

#include <raygui.h>

#include "../../../SceneManager/Scene/Scene.h"
#include "../../../SceneManager/SceneManager.h"

#include "../../../Log/Log.h"

class SceneManager;

class LoadingScene : public Scene
{
public:
    LoadingScene();
    ~LoadingScene();

    void init() override;
    void draw() override;
    void update() override;
    void destroy() override;

    void setNextScene(const std::string &scene_name);
    void completeLoading();

private:
    std::string next_scene_name = "";
    Texture2D background;

    Font font;

    SceneManager *scene_manager = nullptr;
    bool loading_complete = false;
};