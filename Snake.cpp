#include "Snake.h"
#include "Fruit.h"

Snake::Snake()
{
	InitSnakeVariables();
}

void Snake::InitSnakeVariables()
{
	snakeHead.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeHead.setFillColor(sf::Color::Yellow);

	snakeTail.push_back(snakeHead);

	snakeTailPart.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	snakeTailPart.setFillColor(sf::Color::Green);
	snakeTailPart.setPosition(-100, -0100);
}

// Change Snake Head Moving Direction

void Snake::UpdateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir != direction::right)
	{
		dir = direction::left;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir != direction::left)
	{
		dir = direction::right;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir != direction::down)
	{
		dir = direction::up;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir != direction::up)
	{
		dir = direction::down;
	}
}

// Change Snake Head Location and Set Tail Part Location to next Part of Tail Location

void Snake::Move()
{
	// Set Tail Part Location to next Part of Tail Location
	snakeTail[0].setPosition(snakeHead.getPosition());

	for (int i = snakeTail.size()-1; i > 0; i--)
	{
		snakeTail[i].setPosition(snakeTail[i - 1].getPosition());
	}


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
	// Left Border
	if (snakeHead.getPosition().x < 0.f)
	{
		snakeHead.setPosition(WINDOW_SIZE - CELL_SIZE, snakeHead.getGlobalBounds().top);
	}

	// Right Border
	if (snakeHead.getPosition().x >= WINDOW_SIZE)
	{
		snakeHead.setPosition(0.f, snakeHead.getGlobalBounds().top);
	}

	// Top Border
	if (snakeHead.getGlobalBounds().top < 0.f)
	{
		snakeHead.setPosition(snakeHead.getGlobalBounds().left, WINDOW_SIZE - CELL_SIZE);
	}

	// Bottom Border
	if (snakeHead.getGlobalBounds().top + snakeHead.getGlobalBounds().height > WINDOW_SIZE)
	{
		snakeHead.setPosition(snakeHead.getGlobalBounds().left, 0.f);
	}
}

// If Snake

bool Snake::SnakeAteFruit(sf::RectangleShape tail)
{
	if (snakeHead.getPosition() == tail.getPosition())
	{
		snakeTail.push_back(snakeTailPart);
		return true;
	}

	return false;
}

std::vector<sf::RectangleShape> Snake::GetSnakeTail()
{
	return snakeTail;
}

void Snake::Update()
{
	if (clock.getElapsedTime().asSeconds() > 0.05)
	{
		Move();
		UpdateInput();
		clock.restart();
	}

	UpdateWindowCollision();
}

// Draw all RectangleShapes from this class on target ( E.g window )

bool Snake::SnakeCollideWithTail()
{
	for (int i = 0; i < snakeTail.size() - 1; i++)
	{
		if (snakeTail[i].getPosition() == snakeHead.getPosition())
		{
			return true;
		}
	}

	return false;
}

void Snake::RenderSnakeParts(sf::RenderTarget* target)
{
	for (int i = snakeTail.size()-1; i > 0; i--)
	{
		target->draw(snakeTail[i]);
	}

	target->draw(snakeHead);
}
