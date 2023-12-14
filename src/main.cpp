#include <iostream>

#include "Game/Game.h"

int main()
{
    try
    {
        Game::GetInstance().run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}