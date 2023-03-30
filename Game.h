#include "AddSfmlLibraries.h"
#include "Fruit.h"
#include "Snake.h"

class Game
{
public:

	Game();
	~Game();

	void PollEvents();

	void updateGui();
	void renderGui(sf::RenderTarget* target);

	bool Running();
	void UpdateGame();
	void Render();

private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	Snake snake;
	Fruit fruit;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	void InitGameVariables();
	void initText();

};

