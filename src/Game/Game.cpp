#include "Game.h"

Game::Game()
{
    this->init();
}

Game::~Game()
{
    this->destroy();
}

Game &Game::GetInstance()
{
    static Game instance;
    return instance;
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        if (this->m_scene_manager->getCurrentScene() == nullptr)
            break;
        this->draw();
        this->update();
    }
}

void Game::init()
{
    // Log::stopRaylibLogging();
    InitWindow(this->m_window_width, this->m_window_height, "Soul Eater");
    SetTargetFPS(120);
    Log::info("Game initialized");

    this->m_resource_manager = &ResourceManager::getInstance();
    this->m_resource_manager->loadResources();

    this->m_scene_manager = &SceneManager::GetInstance();
    this->m_scene_manager->addScene("start", new StartScene());
    this->m_scene_manager->addScene("game", new GameScene());
    this->m_scene_manager->addScene("loading", new LoadingScene());

    this->m_scene_manager->setCurrentScene("start");
    this->m_scene_manager->setLoadingScene("loading");
    this->m_scene_manager->init();
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (this->m_scene_manager != nullptr)
        this->m_scene_manager->draw();

    EndDrawing();
}

void Game::update()
{
    if (this->m_scene_manager != nullptr)
        this->m_scene_manager->update();
}

void Game::destroy()
{
    if (this->m_scene_manager != nullptr)
        this->m_scene_manager->destroy();

    CloseWindow();
}
