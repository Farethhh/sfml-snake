#include "AddSfmlLibraries.h"

#define CELL_SIZE 20
#define ROW 30

#define WINDOW_SIZE ROW * CELL_SIZE


class Snake
{
private:
	enum direction { left, right, up, down };
	direction dir = right;

	sf::RectangleShape snakeHead;

	void InitSnakeVariables();

	void UpdateInput();
	void Move();
	void UpdateWindowCollision();
public:
	Snake();

	void RenderSnakeParts(sf::RenderTarget* target);
	
	void Update();

	

};

