#include "StartScene.h"

#include <cstdlib>
#include <thread>

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
    this->destroy();
}

void StartScene::init()
{
    this->start_button = {0};
    this->exit_button = {0};

    Image black = GenImageColor(GetScreenWidth(), GetScreenHeight(), BLACK);
    this->background = LoadTextureFromImage(black);

    this->font = GetFontDefault();

    this->start_button = {0, 0, 200, 50};
    this->exit_button = {0, 0, 200, 50};

    this->scene_manager = &SceneManager::GetInstance();
    
}

void StartScene::draw()
{
    DrawTexture(this->background, 0, 0, WHITE);

    this->start_button.x = GetScreenWidth() / 2 - this->start_button.width / 2;
    this->start_button.y = GetScreenHeight() / 2 - this->start_button.height / 2 - 50;

    this->exit_button.x = GetScreenWidth() / 2 - this->exit_button.width / 2;
    this->exit_button.y = GetScreenHeight() / 2 - this->exit_button.height / 2 + 50;

    if (GuiButton(this->start_button, "Start Game"))
    {
        this->start_button_pressed = true;
    }

    if (GuiButton(this->exit_button, "Exit Game"))
    {
        this->exit_button_pressed = true;
    }

    if (this->start_button_pressed)
    {
        this->start_button_pressed = false;
        this->scene_manager->changeScene("game");
        Log::info("Start button pressed");
    }

    if (this->exit_button_pressed)
    {
        this->exit_button_pressed = false;
        this->scene_manager->quitGame();
    }
}

void StartScene::update()
{
}

void StartScene::destroy()
{
    UnloadTexture(this->background);
}
