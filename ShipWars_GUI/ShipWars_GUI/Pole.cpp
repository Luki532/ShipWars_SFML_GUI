#include "Pole.h"

Pole::Pole()
{
	this->initPole();
}

Pole::~Pole()
{
}

void Pole::initPole(int positionx, int positiony)
{
	this->krztalt.setPosition(positionx, positiony);
	this->krztalt.setSize(this->size);
	this->krztalt.setFillColor(this->color);
	//this->krztalt.setOutlineColor(this->outline);;
	//this->krztalt.setOutlineThickness(5);

	this->positionx = positionx;
	this->positiony = positiony;
}

void Pole::clicked(sf::Color color)
{
	this->krztalt.setFillColor(color);
	this->widoczne = !this->widoczne;
}

sf::RectangleShape Pole::getKrztalt()
{
	return this->krztalt;
}

bool Pole::czyWidoczne()
{
	return this->widoczne;
}

void Pole::setStatek()
{
	statek = true;
}

bool Pole::isStatek()
{
	return this->statek;
}

void Pole::initPole()
{

	this->size = sf::Vector2f(40.f, 40.f);
	this->color = sf::Color::Cyan;
	this->outline = sf::Color::Blue;

	this->widoczne = false;
}
