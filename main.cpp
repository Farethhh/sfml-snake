#include <iostream>
#include <ctime>

#include "Game.h"

// -----------------------------------------
// -----------  ISSUES ---------------------
// 
// Kiedy w�� ro�nie jego cz�� spawni si� w z�ej lokalizacji - completed
// Mo�liwe jest prze��czenie kierunku w�a - completed
//
// ----------- THINGS TO ADD --------------
// 
//  Menu
//  Licznik punkt�w
//  �mier�
//	Timer i dobra� pr�dko��
// 
//  Handling Fruit Spawn in SnakeTail - completed
//	�mier� po dotk�ciu ogona - completed
//
// -----------------------------------------
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