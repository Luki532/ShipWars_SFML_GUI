#include "Pole.h"
#include "enums.h"

Pole::Pole()
{
	this->initPole();
	this->crossTexture.loadFromFile("images/Cross.png");
	this->shipTexture.loadFromFile("images/Ship.png");
	this->shipWreckTexture.loadFromFile("images/ShipWreck.png");	
}

Pole::~Pole()
{
	if(this->rodzaj != RodzajPola::Def)
		delete this->Sprite;
}

void Pole::initPole(int positionx, int positiony)
{
	this->krztalt.setPosition(positionx, positiony);
	this->krztalt.setSize(this->size);
	this->krztalt.setFillColor(this->color);
	this->positionx = positionx;
	this->positiony = positiony;
	this->trafiony = false;
	
	this->rodzaj = RodzajPola::Def;
}

void Pole::setColor(sf::Color color)
{
	this->krztalt.setFillColor(color);
}

void Pole::clicked(RodzajPola rodzaj)
{
	this->krztalt.setFillColor(sf::Color::Transparent);
	this->rodzaj = rodzaj;
	this->widoczne = !this->widoczne;
	this->Sprite = new sf::Sprite(this->shipTexture);
	this->Sprite->setPosition(this->positionx, this->positiony);
}

bool Pole::clicked()
{
	if (this->rodzaj == RodzajPola::Def )
	{
		this->rodzaj = RodzajPola::Pudlo;
		this->krztalt.setFillColor(sf::Color::Transparent);
		this->Sprite = new sf::Sprite(this->crossTexture);
		this->Sprite->setPosition(this->positionx, this->positiony);
		return false;
	}
	else if (this->rodzaj == RodzajPola::Statek)
	{
		this->trafiony = true;
		this->krztalt.setFillColor(sf::Color::Transparent);
		this->Sprite = new sf::Sprite(this->shipWreckTexture);
		this->Sprite->setPosition(this->positionx, this->positiony);
		return true;
	}
}

sf::RectangleShape Pole::getKrztalt()
{	
	return this->krztalt;
}

sf::Sprite Pole::getSprite()
{
	return *this->Sprite;
}

bool Pole::czyWidoczne()
{
	return this->widoczne;
}

RodzajPola Pole::getRodzaj()
{
	return this->rodzaj;
}

bool Pole::czyPoleJestWolne()
{
	if (this->rodzaj == RodzajPola::Def)
		return true;
	return false;

}

bool Pole::czyTrafione()
{
	return this->trafiony;
}

void Pole::setRodzaj(RodzajPola rodzaj)
{
	this->rodzaj = rodzaj;
	if (this->rodzaj == RodzajPola::Wrak)
	{
		this->krztalt.setFillColor(sf::Color::Transparent);
		this->Sprite = new sf::Sprite(this->shipWreckTexture);
		this->Sprite->setPosition(this->positionx, this->positiony);
	}

}

void Pole::initPole()
{
	this->size = sf::Vector2f(40.f, 40.f);
	this->color = sf::Color::Cyan;

	this->widoczne = false;
}
