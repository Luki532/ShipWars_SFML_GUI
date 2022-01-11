#include "textBox.h"

void TextBox::inputLogic(int charType)
{
	if (charType != DELETE_KEY && charType != ENTER_KEY && charType != ESCAPE_KEY)
	{
		this->text << static_cast<char>(charType);
	}
	else if (charType == DELETE_KEY)
	{
		if (this->text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	this->textBox.setString(this->text.str() + "_");
}

void TextBox::deleteLastChar()
{
	std::string t = this->text.str();
	std::string newT = "";
	for (int i = 0; i < t.length()-1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	this->textBox.setString(this->text.str());
}

TextBox::TextBox()
{
}
TextBox::TextBox(int size, sf::Color color, bool sel)
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOutlineColor(sf::Color(150, 150, 150, 255));
	this->shape.setOutlineThickness(5);

	this->textBox.setCharacterSize(size);
	this->textBox.setFillColor(color);
	this->isSelected = sel;
	if (sel)
		this->textBox.setString("_");
	else
		this->textBox.setString("");

}

TextBox::~TextBox()
{
}

void TextBox::setFont(sf::Font& font)
{
	this->textBox.setFont(font);
}

void TextBox::setPosition(float x, float y)
{
	this->shape.setPosition(sf::Vector2f(x,y));
	this->textBox.setPosition(x-this->textBox.getGlobalBounds().width/2 + 6, y - this->textBox.getGlobalBounds().height /2 + 4);
}

void TextBox::setSize(sf::Vector2f size)
{
	this->shape.setSize(size);
}



void TextBox::setLimit(bool ToF)
{
	this->hasLimite = ToF;
}

void TextBox::setLimit(bool ToF, int lim)
{
	this->hasLimite = ToF;
	this->limit = lim;
}

void TextBox::setSelected(bool sel)
{
	this->isSelected = sel;

	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		this->textBox.setString(newT);
	}
}

std::string TextBox::getText()
{
	return this->text.str();;
}

void TextBox::drawTo(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->textBox);
}

void TextBox::reset()
{
	this->textBox.setString("");
	this->text.str("");
	this->text.clear();
}

void TextBox::typeOn(int charType)
{
	if (this->isSelected)
	{
		if (charType < 128)
		{
			if (this->hasLimite)
			{
				if (text.str().length() < this->limit)
				{
					inputLogic(charType);
				}
				else if (text.str().length() > this->limit && charType == DELETE_KEY)
				{
					deleteLastChar();
				}
			}
			else 
			{
				inputLogic(charType);
			}
		}
	}
}

