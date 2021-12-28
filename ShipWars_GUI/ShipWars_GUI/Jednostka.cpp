#include "Jednostka.h"

void Jednostka::initJednostka()
{
	this->rodzaj = Statki::Brak;
}

void Jednostka::setJednostka(int positionx, int positiony, Statki rodzaj)
{
	this->positionx = positionx;
	this->positiony = positiony;
	this->rodzaj = rodzaj;
}

bool Jednostka::czyJestStatek(int positonx, int positiony)
{
	if (this->positionx == positionx && this->positiony == positiony)
		return true;
	
	return false;
}
