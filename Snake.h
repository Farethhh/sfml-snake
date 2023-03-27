#include "AddSfmlLibraries.h"

#include "Fruit.h"

class Snake
{
private:
	enum direction { left, right, up, down };
	direction dir = right;

	sf::RectangleShape snakeHeadPart;
	sf::RectangleShape snakeTailPart;

	std::vector<sf::RectangleShape> snakTail;

	void InitSnakeVariables();

	void UpdateInput();
	void Move();
	void UpdateWindowCollision();

public:
	Snake();

	void RenderSnakeParts(sf::RenderTarget* target);
	
	void Update();

	

};

