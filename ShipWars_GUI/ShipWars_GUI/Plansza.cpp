#include "Plansza.h"

Plansza::~Plansza()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		delete[] planszaGracza[i];

	delete[] planszaGracza;
}

void Plansza::initPlansza(sf::RenderWindow* window)
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		this->planszaGracza[i] = new Pole[this->sizeOfBorads];

	initPola();
	this->iloscStatkow = 3;
}

void Plansza::initPola()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
			planszaGracza[i][j].initPole((50 * i) + 5, (50 * j) + 25);
}

void Plansza::setStatek(int n, int positionx, int positiony, Statki rodzaj)
{
	this->statki[n].setJednostka(positionx, positiony, rodzaj);
}

sf::RectangleShape Plansza::getPole(int positionx, int positiony)
{
	return this->planszaGracza[positionx][positiony].getKrztalt();
}

sf::Sprite Plansza::getSprite(int positionx, int positiony)
{
	return this->planszaGracza[positionx][positiony].getSprite();
}

void Plansza::clicked(int positionx, int positiony, RodzajPola rodzaj)
{
	this->planszaGracza[positionx][positiony].clicked(rodzaj);	
}

void Plansza::clicked(int positionx, int positiony)
{
	this->planszaGracza[positionx][positiony].clicked();
}

bool Plansza::czyWidoczne(int positionx, int positiony)
{
	return planszaGracza[positionx][positiony].czyWidoczne();
}

bool Plansza::czyJestStatek(int positionx, int positiony)
{
	if (this->planszaGracza[positionx][positiony].getRodzaj() == RodzajPola::Statek)
		return true;
}

bool Plansza::czyPoleJestWolne(int positionx, int positiony)
{
	return this->planszaGracza[positionx][positiony].czyPoleJestWolne();
}





