#include "LoadingScene.h"

LoadingScene::LoadingScene()
{
}

LoadingScene::~LoadingScene()
{
    this->destroy();
}

void LoadingScene::init()
{

    Image blue = GenImageColor(GetScreenWidth(), GetScreenHeight(), BLUE);
    this->background = LoadTextureFromImage(blue);

    this->font = GetFontDefault();

    this->scene_manager = &SceneManager::GetInstance();
}

void LoadingScene::draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(this->background, 0, 0, WHITE);
    DrawText("Loading...", 10, 10, 20, WHITE);
}

void LoadingScene::update()
{
    if (this->next_scene_name != "")
    {
        int time = GetTime();
        if (time > 4.0f || this->loading_complete)
        {
            this->scene_manager->setScene(this->next_scene_name);
            this->next_scene_name = "";
        }
    }
}

void LoadingScene::destroy()
{
    UnloadTexture(this->background);
}

void LoadingScene::setNextScene(const std::string &scene_name)
{
    this->next_scene_name = scene_name;
}

void LoadingScene::completeLoading()
{
    this->loading_complete = true;
}