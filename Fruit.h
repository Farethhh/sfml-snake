#include "AddSfmlLibraries.h"

#define CELL_SIZE 20
#define ROW 30
#define WINDOW_SIZE ROW * CELL_SIZE

class Fruit
{
private:
	sf::RectangleShape fruitRectangle;

	void InitFruitVariables();

public:
	Fruit();

	void RandFruitPosition();
	void Render(sf::RenderTarget* target);
};

