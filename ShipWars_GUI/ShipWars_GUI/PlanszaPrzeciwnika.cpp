#include "PlanszaPrzeciwnika.h"

void PlanszaPrzeciwnika::initPlanszaPrzeciwnika()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		this->planszaGracza[i] = new Pole[this->sizeOfBorads];

	initPolaPrzeciwnika();
}

void PlanszaPrzeciwnika::initPolaPrzeciwnika()
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
		{
			planszaGracza[i][j].initPole((50 * i) + 560, (50 * j) + 25);
			planszaGracza[i][j].clicked(sf::Color::Red);

		}
}
