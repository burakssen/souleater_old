#include "SceneManager.h"

SceneManager::SceneManager()
{
    this->init();
}

SceneManager::~SceneManager()
{
    this->destroy();
}

SceneManager &SceneManager::GetInstance()
{
    static SceneManager instance;
    return instance;
}

void SceneManager::init()
{
    if (this->current_scene != nullptr)
        this->current_scene->init();
}

void SceneManager::draw()
{
    if (this->current_scene != nullptr)
        this->current_scene->draw();
}

void SceneManager::update()
{
    if (this->current_scene != nullptr)
        this->current_scene->update();
}

void SceneManager::destroy()
{
    for (auto &scene : this->scenes)
    {
        delete scene.second;
        scene.second = nullptr;
    }
    this->scenes.clear();
}

void SceneManager::changeScene(const std::string &scene_name)
{
    static_cast<LoadingScene *>(this->loading_scene)->setNextScene(scene_name);
    this->current_scene = this->loading_scene;
    this->current_scene->init();
}

Scene *SceneManager::getCurrentScene()
{
    return this->current_scene;
}

void SceneManager::quitGame()
{
    if (this->current_scene != nullptr)
    {
        delete this->current_scene;
        this->current_scene = nullptr;
    }
}

void SceneManager::addScene(const std::string &scene_name, Scene *scene)
{
    this->scenes[scene_name] = scene;
}

void SceneManager::setScene(const std::string &scene_name)
{
    this->current_scene = this->scenes[scene_name];
    this->current_scene->init();
}

void SceneManager::setCurrentScene(const std::string &scene_name)
{
    this->current_scene = this->scenes[scene_name];
}

void SceneManager::setLoadingScene(const std::string &scene_name)
{
    this->loading_scene = this->scenes[scene_name];
}

// Path: src/SceneManager/Scene/Scene.cpp