#include "Snake.h"
#include "Fruit.h"
#include <iostream>

Snake::Snake()
{
	InitSnakeVariables();
}

void Snake::InitSnakeVariables()
{
	snakeHeadPart.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeHeadPart.setFillColor(sf::Color::Yellow);

	snakeTail.push_back(snakeHeadPart);

	snakeTailPart.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeTailPart.setFillColor(sf::Color::Green);
	snakeTail.push_back(snakeTailPart);
}

// Change Snake Head Moving Direction

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

// Change Snake Head Location and Set Tail Part Location to next Part of Tail Location

void Snake::Move()
{
	// Set Tail Part Location to next Part of Tail Location
	snakeTail[0].setPosition(snakeHeadPart.getPosition());

	for (int i = snakeTail.size()-1; i > 0; i--)
	{
		snakeTail[i].setPosition(snakeTail[i - 1].getPosition());
	}


	switch (dir)
	{
	case Snake::left:
		snakeHeadPart.setPosition(snakeHeadPart.getPosition().x - CELL_SIZE, snakeHeadPart.getPosition().y);
		break;

	case Snake::right:
		snakeHeadPart.setPosition(snakeHeadPart.getPosition().x + CELL_SIZE, snakeHeadPart.getPosition().y);
		break;

	case Snake::up:
		snakeHeadPart.setPosition(snakeHeadPart.getPosition().x, snakeHeadPart.getPosition().y - CELL_SIZE);
		break;

	case Snake::down:
		snakeHeadPart.setPosition(snakeHeadPart.getPosition().x, snakeHeadPart.getPosition().y + CELL_SIZE);
		break;

	default:
		break;
	}
}

void Snake::UpdateWindowCollision()
{
	// Left Border
	if (snakeHeadPart.getPosition().x < 0.f)
	{
		snakeHeadPart.setPosition(WINDOW_SIZE - CELL_SIZE, snakeHeadPart.getGlobalBounds().top);
	}

	// Right Border
	if (snakeHeadPart.getPosition().x >= WINDOW_SIZE)
	{
		snakeHeadPart.setPosition(0.f, snakeHeadPart.getGlobalBounds().top);
	}

	// Top Border
	if (snakeHeadPart.getGlobalBounds().top < 0.f)
	{
		snakeHeadPart.setPosition(snakeHeadPart.getGlobalBounds().left, WINDOW_SIZE - CELL_SIZE);
	}

	// Bottom Border
	if (snakeHeadPart.getGlobalBounds().top + snakeHeadPart.getGlobalBounds().height > WINDOW_SIZE)
	{
		snakeHeadPart.setPosition(snakeHeadPart.getGlobalBounds().left, 0.f);
	}
}

// If Snake

bool Snake::SnakeAteFruit(sf::RectangleShape tail)
{
	if (snakeHeadPart.getPosition() == tail.getPosition())
	{
		snakeTail.push_back(snakeTailPart);
		return true;
	}
	return false;
}

void Snake::Update()
{
	
	Move();
	UpdateInput();
	UpdateWindowCollision();
}

// Draw all RectangleShapes from this class on target ( E.g window )

void Snake::RenderSnakeParts(sf::RenderTarget* target)
{
	for (int i = snakeTail.size()-1; i > 0; i--)
	{
		target->draw(snakeTail[i]);
	}

	target->draw(snakeHeadPart);
}
