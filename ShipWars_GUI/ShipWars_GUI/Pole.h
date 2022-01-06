#pragma once
#include <SFML/Graphics.hpp>
#include "enums.h"
class Pole
{
private:
	//zmienne
	int positionx;
	int positiony;
	RodzajPola rodzaj;
	bool trafiony;

	bool widoczne;


	//Krzta³t
	sf::RectangleShape krztalt;
	sf::Vector2f size;
	sf::Color color;


	//Texture
	sf::Texture crossTexture;
	sf::Texture shipTexture;
	sf::Texture shipWreckTexture;
	sf::Sprite* Sprite;

public:
	//Konstruktor
	Pole();
	//Destruktor
	~Pole();

	//funckje
	void initPole();
	void initPole(int positionx, int positiony);
	void setColor(sf::Color color);
	void clicked(RodzajPola rodzaj);//Ustawianie jednostek
	bool clicked();//Rozgrywka
	sf::RectangleShape getKrztalt();
	sf::Sprite getSprite();
	bool czyWidoczne();
	RodzajPola getRodzaj();
	bool czyPoleJestWolne();
	bool czyTrafione();
};

