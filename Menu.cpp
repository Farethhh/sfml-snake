#include "Menu.h"
#include <iostream>
#include <fstream>

Menu::Menu()
{
	InitVariables();
}

void Menu::InitVariables()
{
	if (!this->font.loadFromFile("Minecraft.ttf"))
	{
		std::cout << "Nie udalo wczytac sie czcionki";
	}

	for (int i = 0; i < 3; i++)
	{
		menuText[i].setFont(font);
		menuText[i].setFillColor(sf::Color::White);
		menuText[i].setCharacterSize(40);
		menuText[i].setPosition(sf::Vector2f(WINDOW_SIZE/2 - 40, 200 + i*120));
	}
	menuText[0].setString("Start");
	menuText[1].setString("Credits");
	menuText[2].setString("Quit");


	creditsText.setFont(font);
	creditsText.setFillColor(sf::Color::White);
	creditsText.setCharacterSize(20);
	creditsText.setString("This game was made by Szymon Pluta in March 2023.");
	creditsText.setPosition(sf::Vector2f(50, 250));


	std::fstream score("Score.txt");
	std::string highScore;
	score >> highScore;
	score.close();

	std::cout << highScore;
	highScoreText.setFont(font);
	highScoreText.setFillColor(sf::Color::White);
	highScoreText.setCharacterSize(20);
	highScoreText.setString("High Score: " + highScore);
	highScoreText.setPosition(sf::Vector2f(50, 550));
	
	logo.loadFromFile("Logo.png");
	logoSprite.setTexture(logo);
	logoSprite.setPosition(sf::Vector2f(75, 30));
	logoSprite.setScale(2.5,2.5);
}

void Menu::MoveSelectedMenu()
{
	for (int i = 0; i < 3; i++)
	{
		menuText[i].setFillColor(sf::Color::White);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		selectedMenuIndex++;

		if (selectedMenuIndex > 2)
		{
			selectedMenuIndex = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		selectedMenuIndex--;

		if (selectedMenuIndex < 0)
		{
			selectedMenuIndex = 2;
		}
	}

	menuText[selectedMenuIndex].setFillColor(sf::Color::Red);
}

void Menu::EventSelectedMenu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		switch (selectedMenuIndex)
		{
		case 0:

			StartPlaying = true;
			break;

		case 1:
			CreditsPressed = true;
			break;

		case 2:
			exit(0);
			break;
		}
	}
}

void Menu::SetStartPlaying(bool condition)
{
	StartPlaying = condition;
}

bool Menu::GetStartPlaying() const
{
	return StartPlaying;
}

void Menu::ExitCredits()
{
	CreditsPressed = false;
}

void Menu::Update()
{
	if (menuClock.getElapsedTime().asSeconds() > 0.1)
	{
		MoveSelectedMenu();
		menuClock.restart();
	}
	EventSelectedMenu();
}

void Menu::Render(sf::RenderTarget* target)
{
	if (StartPlaying == false)
	{
		target->clear();

		target->draw(highScoreText);
		target->draw(logoSprite);

		for (int i = 0; i < 3; i++)
		{
			target->draw(menuText[i]);
		}

		if (CreditsPressed == true)
		{
			target->clear();
			target->draw(creditsText);
		}
	}
	
}
