#include <ctime>
#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	// Create game object
	Game game;

	// Create Main Loop
	while (game.WindowRunning())
	{
		game.UpdateGame();
		game.Render();

	}

	return 0;
}