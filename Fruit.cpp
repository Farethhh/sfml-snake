#include "Fruit.h"

Fruit::Fruit()
{
	InitFruitVariables();
	RandomizeFruitPosition();
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

void Fruit::RandomizeFruitPosition()
{
	fruitRectangle.setPosition(sf::Vector2f(
		static_cast<float> (rand() % WINDOW_SIZE),
		static_cast<float> (rand() % WINDOW_SIZE)
	)
	);
}

// Set Random Position of Fruit

void Fruit::SetRandFruitPosition(std::vector<sf::RectangleShape> snakeTail)
{
	RandomizeFruitPosition();

	for (int i = 0; i < snakeTail.size() - 1; i++)
	{
		if (snakeTail[i].getPosition() == fruitRectangle.getPosition())
		{
			RandomizeFruitPosition();
			i = -1;
		}
	}

}

void Fruit::Render(sf::RenderTarget* target)
{
	target->draw(fruitRectangle);
}
