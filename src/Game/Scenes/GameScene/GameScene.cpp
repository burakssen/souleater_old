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
    this->m_background = LoadTextureFromImage(background_image);
    this->m_font = GetFontDefault();

    std::cout << "GameScene initialized" << std::endl;
    Player *player = new Player();
    std::cout << "Player: " << player << std::endl;
    this->m_entities.push_back(player);
}

void GameScene::draw()
{
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
    UnloadTexture(this->m_background);
    UnloadFont(this->m_font);
}

// Path: src/Game/Scenes/StartScene/StartScene.cpp