#include "AddSfmlLibraries.h"

class Fruit
{
private:	
	sf::RectangleShape fruitRectangle;
	void InitFruitVariables();
	void RandomizeFruitPosition();

public:
	Fruit();

	sf::RectangleShape GetSprite() const; // tak nie powinno by� | do zmiany

	void SetRandFruitPosition(std::vector<sf::RectangleShape> snakeTail);
	void Render(sf::RenderTarget* target);
};

