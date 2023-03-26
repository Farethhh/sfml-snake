#include "Snake.h"
#include <iostream>

void Snake::InitSnakeVariables()
{
	snakeHead.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeHead.setFillColor(sf::Color::Green);
}

Snake::Snake()
{
	InitSnakeVariables();
}

void Snake::UpdateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir != direction::right)
	{
		dir = direction::left;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir != direction::left)
	{
		dir = direction::right;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir != direction::down)
	{
		dir = direction::up;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir != direction::up)
	{
		dir = direction::down;
	}
}

void Snake::Move()
{
	switch (dir)
	{
	case Snake::left:
		snakeHead.setPosition(snakeHead.getPosition().x - CELL_SIZE, snakeHead.getPosition().y);
		break;

	case Snake::right:
		snakeHead.setPosition(snakeHead.getPosition().x + CELL_SIZE, snakeHead.getPosition().y);
		break;

	case Snake::up:
		snakeHead.setPosition(snakeHead.getPosition().x, snakeHead.getPosition().y - CELL_SIZE);
		break;

	case Snake::down:
		snakeHead.setPosition(snakeHead.getPosition().x, snakeHead.getPosition().y + CELL_SIZE);
		break;

	default:
		break;
	}
}

void Snake::UpdateWindowCollision()
{
	if (snakeHead.getPosition().x < 0.f)
	{
		snakeHead.setPosition(WINDOW_SIZE - CELL_SIZE, snakeHead.getGlobalBounds().top);
	}
	//right
	if (snakeHead.getPosition().x >= WINDOW_SIZE)
	{
		snakeHead.setPosition(0.f, snakeHead.getGlobalBounds().top);
	}

	//top
	if (snakeHead.getGlobalBounds().top < 0.f)
	{
		snakeHead.setPosition(snakeHead.getGlobalBounds().left, WINDOW_SIZE - CELL_SIZE);
	}

	//bottom
	if (snakeHead.getGlobalBounds().top + snakeHead.getGlobalBounds().height > WINDOW_SIZE)
	{

		snakeHead.setPosition(snakeHead.getGlobalBounds().left, 0.f);
	}
}

void Snake::Update()
{
	UpdateInput();
	Move();
	UpdateWindowCollision();
}

// Draw all RectangleShapes from this class on target ( E.g window )

void Snake::RenderSnakeParts(sf::RenderTarget* target)
{
	target->draw(snakeHead);

	std::cout << snakeHead.getGlobalBounds().top << "\n";

}
