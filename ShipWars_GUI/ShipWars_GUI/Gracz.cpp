
#include "Gracz.h"

void Gracz::initGracz(sf::RenderWindow* window)
{
	this->planszaGracza.initPlansza(window);
	this->planszaPrzeciwnika.initPlanszaPrzeciwnika();
	this->akcje = 1;
	this->ustawienie_statkow = 3;
}

void Gracz::updateBoard(sf::Vector2f mousePosView, Gracz* planszaPrzeciwnika)
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->akcje > 0)
			{
				if (this->planszaPrzeciwnika.getPole(i, j).getGlobalBounds().contains(mousePosView) && this->planszaPrzeciwnika.czyWidoczne(i, j))
				{
					this->planszaPrzeciwnika.clicked(i, j, sf::Color::Black);
					planszaPrzeciwnika->clicked(i, j, sf::Color::Black);
					this->akcje--;
				}
			}

	}
}
void Gracz::updateBoard(sf::Vector2f mousePosView)
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->ustawienie_statkow > 0 && this->akcje != 0)
			{
				if (this->planszaGracza.getPole(i, j).getGlobalBounds().contains(mousePosView) && !this->planszaGracza.czyJestStatek(i,j))
				{
					this->planszaGracza.setStatek(this->ustawienie_statkow-3,i,j, Statki::Statek);
					this->planszaGracza.clicked(i, j, sf::Color::Green);
					this->ustawienie_statkow--;
					this->akcje--;

				}
			}
		}
}

void Gracz::renderBoard(sf::RenderWindow* window)
{
	for (int i = 0; i < this->sizeOfBorads; i++)
		for (int j = 0; j < this->sizeOfBorads; j++)
		{
			window->draw(this->planszaGracza.getPole(i, j));
			window->draw(this->planszaPrzeciwnika.getPole(i, j));
		}
}

void Gracz::clicked(int positionx, int positiony, sf::Color color)
{
	this->planszaGracza.clicked(positionx, positiony, sf::Color::Black);
}

void Gracz::resetMoves()
{
	this->akcje = 1;
}

int Gracz::getIloscUstawionych()
{
	return this->ustawienie_statkow;
}

bool Gracz::getAkcje()
{
	return this->akcje;
}
