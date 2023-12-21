#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
    this->destroy();
}

void GameScene::init()
{
    Image background_image = GenImageColor(GetScreenWidth(), GetScreenHeight(), RED);
    this->background = LoadTextureFromImage(background_image);
    this->font = GetFontDefault();

    std::cout << "GameScene initialized" << std::endl;
    Player *player = new Player();
    std::cout << "Player: " << player << std::endl;
    this->m_entities.push_back(player);
}

void GameScene::draw()
{
    // DrawTexture(this->background, 0, 0, WHITE);
    // DrawTextEx(this->font, "GameScene", {10, 10}, 20, 2, WHITE);

    for (Entity *entity : this->m_entities)
    {
        entity->draw();
    }
}

void GameScene::update()
{
    for (Entity *entity : this->m_entities)
    {
        entity->update();
    }
}

void GameScene::destroy()
{
    UnloadTexture(this->background);
    UnloadFont(this->font);
}

// Path: src/Game/Scenes/StartScene/StartScene.cpp