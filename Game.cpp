#include "Game.h"
#include <sstream>
#include <iostream>
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
	initText();
	window->setFramerateLimit(30);
}

void Game::initText()
{
	if (!this->font.loadFromFile("Minecraft.ttf"))
	{
		std::cout << "Nie udalo wczytac sie czcionki";
	}

	guiText.setFont(font);
	guiText.setFillColor(sf::Color::White);
	guiText.setCharacterSize(26);

	endGameText.setFont(font);
	endGameText.setFillColor(sf::Color::Red);
	endGameText.setCharacterSize(60);
	endGameText.setPosition(sf::Vector2f(165, 250));
	endGameText.setString("YOU ARE DEAD");
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
	updateGui();

	if (snake.SnakeAteFruit(fruit.GetSprite()))
	{
		fruit.SetRandFruitPosition(snake.GetSnakeTail());
	}
}

void Game::updateGui()
{
	std::stringstream ss;

	ss << "Points " << snake.GetSnakeTail().size() - 1 << "\n";

	// tutaj bêdzie wczytanie z pliku i rekord punktów zapisany

	guiText.setString(ss.str());
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(guiText);
}

void Game::Render()
{
	window->clear(sf::Color::Black);

	snake.RenderSnakeParts(window);
	fruit.Render(window);
	renderGui(window);

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
