#include "Game.h"

Game::Game()
	: videoMode(800, 600)
	, window(new sf::RenderWindow(this->videoMode, "GAME 2", sf::Style::Close | sf::Style::Titlebar))
{
	InitVariables();
}

Game::~Game()
{
	delete this->window;
}


void Game::InitVariables()
{
	this->window->setFramerateLimit(60);
}

bool Game::Running()
{
	// If Head collides with other parts die

	return true;
}

void Game::Update()
{
	PollEvents();
}

void Game::Render()
{
	this->window->clear();


	this->window->display();
}

void Game::PollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

