#pragma once
#include <SFML/Graphics.hpp>
class Pole
{
private:
	//zmienne
	int positionx;
	int positiony;
	bool statek = false;

	bool widoczne;

	//Krzta³t
	sf::RectangleShape krztalt;
	sf::Vector2f size;
	sf::Color color;
	sf::Color outline;



public:
	//Konstruktor
	Pole();
	//Destruktor
	~Pole();

	//funckje
	void initPole();
	void initPole(int positionx, int positiony);
	void clicked(sf::Color color);
	sf::RectangleShape getKrztalt();
	bool czyWidoczne();
	void setStatek();
	bool isStatek();
};

