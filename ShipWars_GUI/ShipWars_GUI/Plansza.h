#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Pole.h"
#include "Jednostka.h"
#include "enums.h"

class Plansza
{
protected:
	//Wlasciwosci planszy
	int const sizeOfBorads = 10;
	Pole** planszaGracza = new Pole * [sizeOfBorads];

	//Wlasciwosci statkow na planszy
	unsigned int iloscStatkow;
	unsigned int iloscZbitych;
	Jednostka* statki = new Jednostka[iloscStatkow];

public:
	//Destruktor
	virtual	~Plansza();

	//funkcje
	void initPlansza(sf::RenderWindow* window);
	void initPola();
	void setStatek(int n, int positionx, int positiony, Statki rodzaj);
	sf::RectangleShape getPole(int positionx, int positiony);
	sf::Sprite getSprite(int positionx, int positiony);
	void clicked(int positionx, int positiony, RodzajPola rodzaj); //Ustawianie statków
	bool clicked(int positionx, int positiony); //Rozgrywka
	bool czyWidoczne(int positionx, int positiony);
	bool czyJestStatek(int positionx, int positiony);
	bool czyPoleJestWolne(int positionx, int positiony);
	int iloscTrafionych();
	void setRodzaj(int positionx, int positiony, RodzajPola rodzaj);
};

