#include "Game.h"

// Initialization list, make things before constructor
// Window has to be created before other actions

Game::Game()
	: videoMode(WINDOW_SIZE, WINDOW_SIZE)
	, window(new sf::RenderWindow(this->videoMode, "GAME 2", sf::Style::Close | sf::Style::Titlebar))
{
	InitGameVariables();
}

Game::~Game()
{
	delete this->window;
}


void Game::InitGameVariables()
{
	this->window->setFramerateLimit(10);
}

bool Game::Running()
{
	// If Head collides with other parts die

	return true;
}

void Game::UpdateGame()
{
	PollEvents();
	snake.Update();
}

void Game::Render()
{
	window->clear();

	snake.RenderSnakeParts(this->window);

	window->display();
}

// Allows user exit the window by clicking and pressing escape 

void Game::PollEvents()
{
	while (window->pollEvent(sfmlEvent))
	{
		switch (sfmlEvent.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sfmlEvent.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}

