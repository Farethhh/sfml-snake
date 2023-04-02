#include "AddSfmlLibraries.h"

class Snake
{
public:

	Snake();

	bool SnakeAteFruit(sf::RectangleShape tail);

	std::vector<sf::RectangleShape> GetSnakeTail();

	bool SnakeCollideWithTail();
	void RenderSnakeParts(sf::RenderTarget* target);
	void Update();

private:

	enum direction { left, right, up, down };
	direction dir = right;


	sf::RectangleShape snakeHead;

	std::vector<sf::RectangleShape> snakeTail;
	sf::RectangleShape snakeTailPart;

	sf::Clock clock;

	void InitSnakeVariables();

	void UpdateInput();
	void Move();
	void UpdateWindowCollision();
};

