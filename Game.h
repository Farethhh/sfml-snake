#include "AddSfmlLibraries.h"
#include "Snake.h"

class Game
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	Snake snake;

	void InitGameVariables();

public:

	Game();
	~Game();

	bool Running();
	void UpdateGame();
	void Render();

	void PollEvents();
};

