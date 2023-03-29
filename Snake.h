#include "AddSfmlLibraries.h"


class Snake
{
private:
	enum direction { left, right, up, down };
	direction dir = right;

	
	sf::RectangleShape snakeHeadPart;
	sf::RectangleShape snakeTailPart;

	std::vector<sf::RectangleShape> snakeTail;

	void InitSnakeVariables();

	void UpdateInput();
	void Move();
	void UpdateWindowCollision();

public:

	Snake();

	bool SnakeAteFruit(sf::RectangleShape tail);

	std::vector<sf::RectangleShape> GetSnakeTail();

	void RenderSnakeParts(sf::RenderTarget* target);
	void Update();

	

	

};

