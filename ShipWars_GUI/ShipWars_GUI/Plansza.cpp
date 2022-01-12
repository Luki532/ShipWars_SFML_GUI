#include "Plansza.h"

Plansza::~Plansza()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		delete[] this->planszaGracza[i];

	delete[] this->planszaGracza;
}

void Plansza::initPlansza(sf::RenderWindow* window)
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		this->planszaGracza[i] = new Pole[this->sizeOfBorads];

	initPola();
	this->iloscStatkow = 10;
}

void Plansza::initPola()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
			planszaGracza[i][j].initPole((50 * i) + 5, (50 * j) + 75);
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

bool Plansza::clicked(int positionx, int positiony)
{
	if (this->planszaGracza[positionx][positiony].clicked())
	{
		return true;
	}
	return false;
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

int Plansza::iloscTrafionych()
{
	this->iloscZbitych = 0;
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
			if (this->planszaGracza[i][j].czyTrafione())
				this->iloscZbitych++;

	return this->iloscZbitych;
}

void Plansza::setRodzaj(int positionx, int positiony, RodzajPola rodzaj)
{
	this->planszaGracza[positionx][positiony].setRodzaj(rodzaj);
}

void Plansza::resetPlansza()
{
	for(int i = 0; i < this->sizeOfBorads; i++)
		for(int j = 0; j < this->sizeOfBorads; j++)
		this->planszaGracza[i][j].resetPole();
}



