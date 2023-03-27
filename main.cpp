#include <iostream>
#include <ctime>

#include "Game.h"

// -----------------------------------------
// -----------  ISSUES ---------------------
// 
// Kiedy w�� ro�nie jego cz�� spawni si� w z�ej lokalizacji
// Mo�liwe jest prze��czenie kierunku w�a
//
//
//
//
// -----------------------------------------

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	// Create game object
	Game game;

	// Create Main Loop
	while (game.Running())
	{
		game.UpdateGame();
		game.Render();
	}

	return 0;
}