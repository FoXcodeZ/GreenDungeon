#include <iostream>
#include "Game.hpp"

int main(int argc, char* argv[])
{
    std::cout << "Green Dungeon" << std::endl;
    Game game;

    game.Initialize();
    game.Run();
    game.Shutdown();

    return 0;
}