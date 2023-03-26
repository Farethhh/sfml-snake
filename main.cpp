#include <iostream>
#include <ctime>

#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	while (game.Running())
	{
		game.Update();
		game.Render();
	}

	return 0;
}