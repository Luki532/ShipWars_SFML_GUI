#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "Plansza.h"
#include "PlanszaPrzeciwnika.h"
#include "Gracz.h"
#include "Button.h"
#include "enums.h"
#include "TextBox.h"

//Klasa dzia³ania ca³ej gry


class Game
{
private:
	//zmienne
	//Okno gry
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;
	sf::Text playerName;
	sf::Text enemyName;
	sf::Text gameName;
	sf::Text playerAConfig;
	sf::Text playerNameInput;
	sf::Text playerBConfig;


	//Button
	std::map<std::string, Button*> buttons;

	//TextBox
	TextBox* playerOne;
	TextBox* playerTwo;


	//Game logic
	Gracz graczA;
	Gracz graczB;
	bool playerA; //czyja tura
	int akcje;

	//Game stage
	Stage poprzedniEtap;
	Stage etap;

	//funkcje
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initButton();
	void initTextBox();

public:
	//konstruktor
	Game();
	//destruktor
	virtual	~Game();

	//dostêp
	const bool running() const;

	//funkcje
	void pollEvents();
	void update();
	void updateMousePositions();
	void updateText(sf::Text* text, std::string s);
	void updateButtons();
	void updateRozgrywka();
	void render();
	void renderText(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
	void renderRozgrywka(sf::RenderTarget& target);
	void renderTextBox(sf::RenderTarget& target);
	void resetAkcje();
};



