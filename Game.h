#include "AddSfmlLibraries.h"

class Game
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	void InitVariables();

public:

	Game();
	~Game();

	bool Running();
	void Update();
	void Render();

	void PollEvents();
};

