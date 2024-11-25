#include <iostream>
#include "Game.hpp"

int main(int argc, char* argv[])
{
    std::cout << "Green Dungeon" << std::endl;
    Game game;

    if (!game.Initialize())
    {
        return -1;
    }

    game.Run();
    game.Shutdown();
    return 0;
}