#include "AddSfmlLibraries.h"

class Fruit
{
public:

	Fruit();

	sf::RectangleShape GetSprite() const; // tak nie powinno byæ | do zmiany

	void SetRandFruitPosition(std::vector<sf::RectangleShape> snakeTail);
	void Render(sf::RenderTarget* target);

private:

	sf::RectangleShape fruitRectangle;

	void InitFruitVariables();
	void RandomizeFruitPosition();
};

