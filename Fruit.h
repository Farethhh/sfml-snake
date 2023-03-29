#include "AddSfmlLibraries.h"

#define CELL_SIZE 20
#define ROW 30
#define WINDOW_SIZE ROW * CELL_SIZE

class Fruit
{
private:	
	sf::RectangleShape fruitRectangle;
	void InitFruitVariables();
	void RandomizeFruitPosition();

public:
	Fruit();

	sf::RectangleShape GetSprite() const; // tak nie powinno byæ | do zmiany

	void SetRandFruitPosition(std::vector<sf::RectangleShape> snakeTail);
	void Render(sf::RenderTarget* target);
};

