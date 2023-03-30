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
// 
//  Menu
//  Licznik punktów
//  Œmieræ
//	Timer i dobraæ prêdkoœæ
// 
//  Handling Fruit Spawn in SnakeTail - completed
//	Œmieræ po dotkêciu ogona - completed
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