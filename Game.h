#include "AddSfmlLibraries.h"
#include "Fruit.h"
#include "Snake.h"
#include "Menu.h"

class Game
{
public:

	Game();
	~Game();

	bool WindowRunning() const;

	void PollEvents();

	void UpdateGui();
	void UpdateGame();
	void Render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	Snake snake;
	Fruit fruit;
	Menu menu;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	bool IsGameRunning();

	void InitGameVariables();
	void initText();

};

