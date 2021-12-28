#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Pole.h"
#include "Jednostka.h"

class Plansza
{
protected:
	//Wlasciwosci planszy
	int const sizeOfBorads = 10;
	Pole** planszaGracza = new Pole * [sizeOfBorads];

	//Wlasciwosci statkow na planszy
	unsigned int iloscStatkow;
	Jednostka* statki = new Jednostka[iloscStatkow];

public:
	//Destruktor
	virtual	~Plansza();

	//funkcje
	void initPlansza(sf::RenderWindow* window);
	void initPola();
	void setStatek(int n, int positionx, int positiony, Statki rodzaj);
	sf::RectangleShape getPole(int positionx, int positiony);
	void clicked(int positionx, int positiony, sf::Color);
	bool czyWidoczne(int positionx, int positiony);
	bool czyJestStatek(int positionx, int positiony);

};

