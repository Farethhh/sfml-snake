#include "Fruit.h"

Fruit::Fruit()
{
	InitFruitVariables();
	RandFruitPosition();
}

sf::RectangleShape Fruit::GetSprite() const
{
	return fruitRectangle;
}

void Fruit::InitFruitVariables()
{
	fruitRectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	fruitRectangle.setFillColor(sf::Color::Red);
}

// Set Random Position of Fruit

void Fruit::RandFruitPosition()
{
	fruitRectangle.setPosition(sf::Vector2f(
		static_cast<float> (rand() % WINDOW_SIZE),
		static_cast<float> (rand() % WINDOW_SIZE)
	)
	);

}

void Fruit::Render(sf::RenderTarget* target)
{
	target->draw(fruitRectangle);
}
