#include "Game.h"

// Initialization list, make things before constructor
// Window has to be created before other actions

Game::Game()
	: videoMode(WINDOW_SIZE, WINDOW_SIZE)
	, window(new sf::RenderWindow(videoMode, "GAME 2", sf::Style::Close | sf::Style::Titlebar))
	, fruit()
{
	InitGameVariables();
}

Game::~Game()
{
	delete window;
}


void Game::InitGameVariables()
{
	window->setFramerateLimit(20);
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

	if (snake.SnakeAteFruit(fruit.GetSprite()))
	{
		fruit.RandFruitPosition();
	}
}

void Game::Render()
{
	window->clear(sf::Color::White);

	snake.RenderSnakeParts(window);
	fruit.Render(window);

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

