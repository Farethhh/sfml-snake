#include "Game.h"


Game::Game()
	: videoMode(800, 600)
	, window(new sf::RenderWindow(this->videoMode, "GAME 2", sf::Style::Close | sf::Style::Titlebar))
{

}

Game::~Game()
{
}

bool Game::Running()
{
	// If Head collides with other parts die

	return true;
}

void Game::Update()
{
}

void Game::Render()
{
}
