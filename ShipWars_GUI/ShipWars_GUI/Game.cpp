#include "Game.h"


//Private
void Game::initVariables()
{
	this->window = nullptr;
	this->playerA = true;
	this->graczA.initGracz(this->window);
	this->graczB.initGracz(this->window);

	this->etap = Stage::rozstawienieGraczaA;
	this->akcje = 1;
}

void Game::initWindow()
{

	/*
	Zmieniæ jeszcze pozycjê w przyciskach (chowanie)
	*/
	this->videoMode.height = 650;
	this->videoMode.width = 1070;
	this->window = new sf::RenderWindow(this->videoMode, "ShipWars", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/GothicA1-Light.ttf"))
	{
		std::cout << "ERROR::GAME::INIT::Failed to load font! \n";
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(18);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setPosition(0, 0);
	this->uiText.setString("TEST");

	this->playerName.setFont(this->font);
	this->playerName.setCharacterSize(18);
	this->playerName.setFillColor(sf::Color::White);
	this->playerName.setPosition(0, 20);
	this->playerName.setString("TEST");

	this->enemyName.setFont(this->font);
	this->enemyName.setCharacterSize(18);
	this->enemyName.setFillColor(sf::Color::White);
	this->enemyName.setString("Plansza Gracza ");
	this->enemyName.setPosition(this->window->getSize().x - this->enemyName.getGlobalBounds().width, 20);
}

void Game::initButton()
{

	this->buttons["CHANGE_SEAT_BTN"] = new Button(40, 590, 150, 50,
		&this->font, "Zakoncz ture",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["CHANGE_PLAYER_TO_A_BTN"] = new Button(190, 590, 150, 50,
		&this->font, "Kolej gracza A",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->buttons["CHANGE_PLAYER_TO_B_BTN"] = new Button(190, 590, 150, 50,
		&this->font, "Kolej gracza B",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}

//Public
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initButton();


}

Game::~Game()
{	
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}


	delete this->window;

}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->updateButtons();
	this->updateRozgrywka();
	
}

void Game::pollEvents()
{
	//EVENT POLLING
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
		{
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else if (this->ev.key.code == sf::Keyboard::Tab)
			{
				if (etap == Stage::rozstawienieGraczaA)
					continue;
				this->playerA = !this->playerA;
			}
				
		}
			break;
		}
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText(sf::Text* text, std::string s)
{

	std::stringstream ss;

	if (this->playerA)
		ss << s;
	else
		ss << s;

	this->enemyName.setPosition(this->window->getSize().x - this->enemyName.getGlobalBounds().width - 20, 20);
	text->setString(ss.str());
}

void Game::render()
{
	this->window->clear();

	//Wyœwietl grê 
	this->renderText(*this->window);
	this->renderButtons(*this->window);
	this->renderRozgrywka(*this->window);


	this->window->display();
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
	target.draw(this->playerName);
	target.draw(this->enemyName);
}

void Game::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->akcje == 0)
		this->buttons["CHANGE_SEAT_BTN"]->showButton();
	if(this->etap == Stage::przejscie)
		this->buttons["CHANGE_SEAT_BTN"]->hideButton();


	if (this->buttons["CHANGE_SEAT_BTN"]->isPressed() && this->akcje == 0)
	{
		if(this->etap != Stage::przejscie)
			this->poprzedniEtap = this->etap;
		this->etap = Stage::przejscie;

		if (this->poprzedniEtap == Stage::rozstawienieGraczaB)
			this->buttons["CHANGE_PLAYER_TO_A_BTN"]->showButton();
		else if (this->playerA)
			this->buttons["CHANGE_PLAYER_TO_B_BTN"]->showButton();
		else
			this->buttons["CHANGE_PLAYER_TO_A_BTN"]->showButton();

	}

	if (this->buttons["CHANGE_PLAYER_TO_B_BTN"]->isPressed() && this->playerA)
	{
		this->resetAkcje();

		if (this->poprzedniEtap == Stage::rozstawienieGraczaA)
			this->etap = Stage::rozstawienieGraczaB;
		else
		{
			this->etap = Stage::rozgrywka;
			this->playerA = false;
		}

		this->buttons["CHANGE_PLAYER_TO_B_BTN"]->hideButton();
	}

	if (this->buttons["CHANGE_PLAYER_TO_A_BTN"]->isPressed() && (!this->playerA || this->poprzedniEtap == Stage::rozstawienieGraczaB))
	{
		this->resetAkcje();
		this->etap = Stage::rozgrywka;
		this->playerA = true;
		this->buttons["CHANGE_PLAYER_TO_A_BTN"]->hideButton();
	}
}

void Game::updateRozgrywka()
{
	switch (etap)
	{
	case Stage::start:
	{

	}
	break;
	case Stage::rozstawienieGraczaA:
	{
		this->graczA.updateBoard(this->mousePosView);
		this->updateText(&this->uiText ,"Rozstawienie gracza A, pozostalo statkow: " + std::to_string(this->graczA.getIloscUstawionych()));
		this->updateText(&this->playerName, "Plansza Gracza A");
		this->updateText(&this->enemyName, "Plansza Gracza B");

		if (this->graczA.getIloscUstawionych() == 0)
		{
			this->updateText(&this->uiText, "Zakonczono ustawianie statkow Gracza A, zakoncz ture!");
			this->akcje = 0;
		}
	}
	break;
	case Stage::rozstawienieGraczaB:
	{
		this->graczB.updateBoard(this->mousePosView);
		this->updateText(&this->uiText, "Rozstawienie gracza B, pozostalo statkow: " + std::to_string(this->graczB.getIloscUstawionych()));
		this->updateText(&this->playerName, "Plansza Gracza B");
		this->updateText(&this->enemyName, "Plansza Gracza A");
		if (this->graczB.getIloscUstawionych() == 0)
		{
			this->updateText(&this->uiText, "Zakonczono ustawianie statkow Gracza B, zakoncz ture!");
			this->akcje = 0;

		}
	}
	break;
	case Stage::przejscie:
	{
		this->updateText(&this->uiText, "Przekarz kontrole!");
	}
	break;
	case Stage::rozgrywka:
	{
		if (playerA)
		{
			this->graczA.updateBoard(this->mousePosView, &graczB);
			this->updateText(&this->uiText, "Tura Gracz A");
			this->updateText(&this->playerName, "Plansza Gracza A");
			this->updateText(&this->enemyName, "Plansza Gracza B");
			if (!this->graczA.getAkcje())
				this->akcje = 0;

			if (this->graczB.czyKoniec())
				this->etap = Stage::koniec;

		}
		else
		{
			this->graczB.updateBoard(this->mousePosView, &graczA);
			this->updateText(&this->uiText, "Tura Gracz B");
			this->updateText(&this->playerName, "Plansza Gracza A");
			this->updateText(&this->enemyName, "Plansza Gracza B");
			if (!this->graczB.getAkcje())
				this->akcje = 0;


			if (this->graczA.czyKoniec())
				this->etap = Stage::koniec;

		}
	}
		break;
	case Stage::koniec:
	{
		if(this->graczA.czyPrzegral())
			this->updateText(&this->uiText, "Koniec gry, wygrywa gracz B");
		else
			this->updateText(&this->uiText, "Koniec gry, wygrywa gracz A");

	}
		break;
	default:
		break;
	}


}

void Game::resetAkcje()
{
	this->akcje = 1;
}

void Game::renderRozgrywka(sf::RenderTarget& target)
{

	switch (etap)
	{
	case Stage::start:
		break;
	case Stage::rozstawienieGraczaA:
	{
		this->graczA.renderBoard(this->window);
		this->graczA.resetMoves();
	}
		break;
	case Stage::rozstawienieGraczaB:
	{
		this->graczB.renderBoard(this->window);
		this->graczB.resetMoves();
	}
		break;
	case Stage::przejscie:
	{


	}
		break;
	case Stage::rozgrywka:
	{
		if (playerA)
		{
			this->graczA.renderBoard(this->window);
			this->graczB.resetMoves();
		}
		else
		{
			this->graczB.renderBoard(this->window);
			this->graczA.resetMoves();
		}
	}
		break;
	case Stage::koniec:
		break;
	default:
		break;
	}

}

void Game::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(&target);
	}
}
