#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Plansza.h"
#include "PlanszaPrzeciwnika.h"
#include "enums.h"
#include "TextBox.h"

class Gracz
{
private:
	//Game Boards
	int const iloscStatkow = 10;
	int const sizeOfBorads = 10;
	Plansza planszaGracza;
	PlanszaPrzeciwnika planszaPrzeciwnika;
	int akcje;
	int ustawienie_statkow;
	int zbitychStatkow;
	bool czyPrzegrany = false;
	std::string playerName;

public:
	//funkcje
	void initGracz(sf::RenderWindow* window);
	void updateBoard(sf::Vector2f mousePosView, Gracz* planszaPrzeciwnika);
	void updateBoard(sf::Vector2f mousePosView);
	void setPlayerName(std::string name);

	void renderBoard(sf::RenderWindow*);
	//wcisniecie pola
	bool clicked(int positionx, int positiony);
	//resetowanie wartoœci co turê
	void resetMoves();
	int getIloscUstawionych();
	bool getAkcje();
	bool czyJestStatek(int positionx, int positiony);
	int iloscTrafionych();
	bool czyKoniec();
	bool czyPrzegral();
	void setPosition(int positionx, int positiony);
	std::string getName();
	void resetGracz();
};

