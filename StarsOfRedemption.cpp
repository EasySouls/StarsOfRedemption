#include <iostream>
#include "Game.h"

int main()
{
    srand(time(0));

    Game game;
    game.Init();

    while (game.GetIsRunning())
    {
        game.MainMenu();
    }
}

