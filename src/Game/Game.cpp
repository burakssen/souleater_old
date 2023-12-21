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
        if (this->scene_manager->getCurrentScene() == nullptr)
            break;
        this->draw();
        this->update();
    }
}

void Game::init()
{
    // Log::stopRaylibLogging();
    InitWindow(this->window_width, this->window_height, "Soul Eater");
    SetTargetFPS(120);
    Log::info("Game initialized");

    this->resource_manager = &ResourceManager::getInstance();
    this->resource_manager->loadResources();

    this->scene_manager = &SceneManager::GetInstance();
    this->scene_manager->addScene("start", new StartScene());
    this->scene_manager->addScene("game", new GameScene());
    this->scene_manager->addScene("loading", new LoadingScene());

    this->scene_manager->setCurrentScene("start");
    this->scene_manager->setLoadingScene("loading");
    this->scene_manager->init();
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (this->scene_manager != nullptr)
        this->scene_manager->draw();

    EndDrawing();
}

void Game::update()
{
    if (this->scene_manager != nullptr)
        this->scene_manager->update();
}

void Game::destroy()
{
    if (this->scene_manager != nullptr)
        this->scene_manager->destroy();

    CloseWindow();
}
