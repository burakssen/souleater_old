#pragma once

#include <string>
#include <map>

#include "Scene/Scene.h"

#include "../Game/Scenes/LoadingScene/LoadingScene.h"

#include "../Log/Log.h"

class LoadingScene;

class SceneManager
{
private:
    SceneManager();
    ~SceneManager();

public:
    static SceneManager &GetInstance();

    void init();
    void draw();
    void update();
    void destroy();

    SceneManager(const SceneManager &) = delete;
    SceneManager &operator=(const SceneManager &) = delete;
    SceneManager(SceneManager &&) = delete;
    void addScene(const std::string &scene_name, Scene *scene);
    void setScene(const std::string &scene_name);
    void setLoadingScene(const std::string &scene_name);

    void setCurrentScene(const std::string &scene_name);
    void changeScene(const std::string &scene_name);
    Scene *getCurrentScene();
    void quitGame();

private:
    Scene *m_current_scene = nullptr;
    Scene *m_loading_scene = nullptr;
    std::map<std::string, Scene *> scenes;
};