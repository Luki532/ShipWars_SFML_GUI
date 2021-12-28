#pragma once
#include <SFML/Graphics.hpp>
#include "enums.h"

class Jednostka
{
private:
	int positionx;
	int positiony;
	bool trafiony;
	Statki rodzaj;

public:
	
	//funkcje
	void initJednostka();
	void setJednostka(int positionx, int positiony, Statki rodzaj);
	bool czyJestStatek(int positionx, int positiony);
};

