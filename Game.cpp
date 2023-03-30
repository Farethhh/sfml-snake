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
	window->setFramerateLimit(30);
}

bool Game::Running()
{
	if (snake.SnakeCollideWithTail() == true)
	{
		return false;
	}

	return true;
}

void Game::UpdateGame()
{
	PollEvents();
	snake.Update();

	if (snake.SnakeAteFruit(fruit.GetSprite()))
	{
		fruit.SetRandFruitPosition(snake.GetSnakeTail());
	}
}

void Game::Render()
{
	window->clear(sf::Color::Black);

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

