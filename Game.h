#include "AddSfmlLibraries.h"
#include "Fruit.h"
#include "Snake.h"
#include "Menu.h"
#include <fstream>

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

	std::fstream score;
	int points;
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

	void UpdateHighScore();
};

