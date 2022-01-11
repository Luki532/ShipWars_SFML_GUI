#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox
{
private:
	sf::Text textBox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimite = false;
	int limit;
	sf::RectangleShape shape;

	void inputLogic(int charType);
	void deleteLastChar();
	
public:
	TextBox();
	TextBox(int size, sf::Color color, bool sel);
	~TextBox();
	void setFont(sf::Font& font);
	void setPosition(float x, float y);
	void setSize(sf::Vector2f size);
	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelected(bool sel);
	std::string getText();
	void drawTo(sf::RenderWindow& window);
	void reset();

	void typeOn(int charType);

};