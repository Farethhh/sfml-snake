#include "AddSfmlLibraries.h"

class Menu
{
public:

	Menu();

	void Update();
	void Render(sf::RenderTarget* target);

	void SetStartPlaying(bool condition);
	bool GetStartPlaying() const;

	void ExitCredits();
private:

	sf::Event sfmlEvent;
	int selectedMenuIndex = 0;

	bool StartPlaying = false;
	bool CreditsPressed = false;

	sf::Font font;
	sf::Text menuText[3];
	sf::Text creditsText;
	sf::Text highScoreText;

	sf::Texture logo;
	sf::Sprite logoSprite;

	sf::Clock menuClock;

	void InitVariables();

	void MoveSelectedMenu();
	void EventSelectedMenu();
};

