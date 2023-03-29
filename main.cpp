#include <iostream>
#include <ctime>

#include "Game.h"

// -----------------------------------------
// -----------  ISSUES ---------------------
// 
// Kiedy w¹¿ roœnie jego czêœæ spawni siê w z³ej lokalizacji - completed
// Mo¿liwe jest prze³¹czenie kierunku wê¿a - completed
//
// ----------- THINGS TO ADD --------------
//  Menu
//  Handling Fruit Spawn in SnakeTail - completed
//  MAP
//	Œmieræ po dotkêciu ogona
//  Licznik punktów
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