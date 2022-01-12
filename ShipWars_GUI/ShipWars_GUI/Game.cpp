#include "Game.h"


//Private
void Game::initVariables()
{
	this->window = nullptr;
	this->playerA = true;
	this->graczA.initGracz(this->window);
	this->graczB.initGracz(this->window);

	this->etap = Stage::start;
	this->akcje = 1;
	this->iloscTur = 1;
	this->czyZapisano = false;
}

void Game::initWindow()
{
	this->videoMode.height = 650;
	this->videoMode.width = 1070;
	this->window = new sf::RenderWindow(this->videoMode, "ShipWars", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(true);
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
	//Tytu³ gry
	this->gameName.setFont(this->font);
	this->gameName.setCharacterSize(64);
	this->gameName.setFillColor(sf::Color::White);
	this->gameName.setString("ShipWars");
	this->gameName.setPosition(this->window->getSize().x/2 - this->gameName.getGlobalBounds().width/2, 50);

	//Konfiguracja gracza A
	this->playerAConfig.setFont(this->font);
	this->playerAConfig.setCharacterSize(32);
	this->playerAConfig.setFillColor(sf::Color::White);
	this->playerAConfig.setString("Gracz pierwszy");
	this->playerAConfig.setPosition(this->window->getSize().x / 2 - this->playerAConfig.getGlobalBounds().width / 2, 50);

	this->playerNameInput.setFont(this->font);
	this->playerNameInput.setCharacterSize(18);
	this->playerNameInput.setFillColor(sf::Color::White);
	this->playerNameInput.setString("Wpisz nazwe gracza, wcisnij enter");
	this->playerNameInput.setPosition(this->window->getSize().x / 2 - this->playerNameInput.getGlobalBounds().width / 2, 150);

	//Konfiguracja gracza B
	this->playerBConfig.setFont(this->font);
	this->playerBConfig.setCharacterSize(32);
	this->playerBConfig.setFillColor(sf::Color::White);
	this->playerBConfig.setString("Gracz drugi");
	this->playerBConfig.setPosition(this->window->getSize().x / 2 - this->playerBConfig.getGlobalBounds().width / 2, 50);


	//Obecny etap
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(18);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setPosition(0, 0);
	this->uiText.setString("TEST");

	//Podpis planszy gracza A
	this->playerName.setFont(this->font);
	this->playerName.setCharacterSize(18);
	this->playerName.setFillColor(sf::Color::White);
	this->playerName.setPosition(0, 20);
	this->playerName.setString("TEST");

	//Podpis planszy gracza B
	this->enemyName.setFont(this->font);
	this->enemyName.setCharacterSize(18);
	this->enemyName.setFillColor(sf::Color::White);
	this->enemyName.setString("Plansza Gracza ");
	this->enemyName.setPosition(this->window->getSize().x - this->enemyName.getGlobalBounds().width, 20);

	//Koniec gry
	this->wynikGry.setFont(this->font);
	this->wynikGry.setCharacterSize(32);
	this->wynikGry.setFillColor(sf::Color::White);
	this->wynikGry.setString("Koniec gry, wygrywa gracz");
	this->wynikGry.setPosition(this->window->getSize().x / 2 - this->wynikGry.getGlobalBounds().width / 2, 50);

	this->gameResult.setFont(this->font);
	this->gameResult.setCharacterSize(24);
	this->gameResult.setFillColor(sf::Color::White);
	this->gameResult.setString("Wynik gry:");
	this->gameResult.setPosition(this->window->getSize().x / 2 - this->gameResult.getGlobalBounds().width / 2, 50);



	for (int i = 0; i < 10; i++)
	{
		this->gameResultTab[i].setFont(this->font);
		this->gameResultTab[i].setCharacterSize(24);
		this->gameResultTab[i].setFillColor(sf::Color::White);
		this->gameResultTab[i].setString("Wynik gry:");
		this->gameResultTab[i].setPosition(30, 120+40*i);
	}

}

void Game::initButton()
{
	//Menu
	this->buttons["START_GAME"] = new Button(this->window->getSize().x/2 - 75, 250, 175, 50,
		&this->font, "Nowa Gra",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);

	this->buttons["RECORDS"] = new Button(this->window->getSize().x / 2 - 75, 325, 175, 50,
		&this->font, "Tabela wynikow",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);

	this->buttons["END"] = new Button(this->window->getSize().x / 2 - 75, 400, 175, 50,
		&this->font, "Koniec Gry",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);

	//Nowy gracz
	this->buttons["ADD_PLAYER"] = new Button(this->window->getSize().x / 2 - 75, 300, 175, 50,
		&this->font, "Przejdz dalej",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);
	this->buttons["NEXT_NEW_PLAYER"] = new Button(40, 590, 150, 50,
		&this->font, "Kolejny gracz",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);

	//Rozgrywka
	this->buttons["CHANGE_SEAT_BTN"] = new Button(40, 590, 150, 50,
		&this->font, "Zakoncz ture",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["CHANGE_PLAYER_TO_A_BTN"] = new Button(190, 590, 150, 50,
		&this->font, "Kontynuuj",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["CHANGE_PLAYER_TO_B_BTN"] = new Button(190, 590, 150, 50,
		&this->font, "Kontynuuj",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


	//Powrot
	this->buttons["BACK"] = new Button(this->window->getSize().x / 2 - 75, 550, 175, 50,
		&this->font, "Powrot",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 20);

}

void Game::initTextBox()
{
	this->playerOne = new TextBox(28, sf::Color::Black, false);
	this->playerOne->setFont(this->font);
	this->playerOne->setPosition(this->window->getSize().x / 2 - 145, 200);
	this->playerOne->setSize(sf::Vector2f(300, 50));
	this->playerOne->setLimit(true, 18);


	this->playerTwo = new TextBox(28, sf::Color::Black, false);
	this->playerTwo->setFont(this->font);
	this->playerTwo->setPosition(this->window->getSize().x / 2 - 145, 200);
	this->playerTwo->setSize(sf::Vector2f(300, 50));
	this->playerTwo->setLimit(true, 18);
}

//Public
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initButton();
	this->initTextBox();


}

Game::~Game()
{	
	delete this->playerOne;
	delete this->playerTwo;

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
		case sf::Event::TextEntered:
			this->playerOne->typeOn(static_cast<char>(this->ev.text.unicode));
			this->playerTwo->typeOn(static_cast<char>(this->ev.text.unicode));

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
	this->renderTextBox(*this->window);

	this->window->display();
}

void Game::renderText(sf::RenderTarget& target)
{
	if (this->etap == Stage::start)
	{
		target.draw(this->gameName);
	}
	else if (this->etap == Stage::nowa_gra_A)
	{
		target.draw(this->playerAConfig);
		target.draw(this->playerNameInput);
	}
	else if (this->etap == Stage::nowa_gra_B)
	{
		target.draw(this->playerBConfig);
		target.draw(this->playerNameInput);
	}
	else if (this->etap == Stage::rozstawienieGraczaA || this->etap == Stage::rozstawienieGraczaB || this->etap == Stage::rozgrywka)
	{
		target.draw(this->uiText);
		target.draw(this->playerName);
		target.draw(this->enemyName);
	}
	else if (this->etap == Stage::koniec)
	{
		target.draw(this->wynikGry);
		target.draw(this->gameResult);
		
		
	}
	else if (this->etap == Stage::tabela)
	{
		target.draw(this->wynikGry);

		for (int i = 0; i < 10; i++)
			target.draw(this->gameResultTab[i]);
	}
	else
	{
		target.draw(this->uiText);
	}
}

void Game::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->etap == Stage::start)
	{
		this->buttons["END"]->changePos(this->window->getSize().x / 2 - 75, 400, "Koniec Gry");
		this->buttons["START_GAME"]->showButton();
		this->buttons["RECORDS"]->showButton();
		this->buttons["END"]->showButton();
	}
	else
	{
		this->buttons["START_GAME"]->hideButton();
		this->buttons["RECORDS"]->hideButton();
		this->buttons["END"]->hideButton();
	}

	if (this->etap == Stage::nowa_gra_A || this->etap == Stage::nowa_gra_B)
	{
		this->buttons["ADD_PLAYER"]->showButton();
		this->buttons["BACK"]->showButton();
	}
	else
	{
		this->buttons["ADD_PLAYER"]->hideButton();
		this->buttons["BACK"]->hideButton();
	}

	//Wcisniety przycisk START GAME
	if (this->buttons["RECORDS"]->isPressed())
		this->etap = Stage::tabela;
	
	//Wcisniety przycisk TABLICA WYNIKOW
	if (this->buttons["START_GAME"]->isPressed())
		this->etap = Stage::nowa_gra_A;

	//Wcisniety przycisk END
	if (this->buttons["END"]->isPressed())
		this->window->close();

	//Wcisniecie ADD_PLAYER
	if (this->buttons["ADD_PLAYER"]->isPressed() && this->etap == Stage::nowa_gra_A)
	{
		if (this->playerOne->getText().length() == 0)
		{
			this->graczA.setPlayerName("Gracz");
		}
		else
		{
			this->graczA.setPlayerName(this->playerOne->getText());
			this->playerOne->reset();
			this->playerTwo->reset();
		}
		this->poprzedniEtap = this->etap;
		this->etap = Stage::przejscie;
		
	}
	else if (this->buttons["ADD_PLAYER"]->isPressed() && this->etap == Stage::nowa_gra_B)
	{
		if (this->playerTwo->getText().length() == 0)
		{
			this->graczB.setPlayerName("Gracz");
		}
		else
		{
			this->graczB.setPlayerName(this->playerTwo->getText());
			this->playerOne->reset();
			this->playerTwo->reset();
		}
		this->poprzedniEtap = this->etap;
		this->start = std::chrono::high_resolution_clock::now();
		this->etap = Stage::przejscie;
	}
	


	if (this->poprzedniEtap == Stage::nowa_gra_A || this->poprzedniEtap == Stage::nowa_gra_B)
		this->buttons["NEXT_NEW_PLAYER"]->showButton();
	else
		this->buttons["NEXT_NEW_PLAYER"]->hideButton();

	if (this->buttons["NEXT_NEW_PLAYER"]->isPressed() && this->poprzedniEtap == Stage::nowa_gra_A)
	{
		this->poprzedniEtap = this->etap;
		this->etap = Stage::nowa_gra_B;
	}
	else if (this->buttons["NEXT_NEW_PLAYER"]->isPressed() && this->poprzedniEtap == Stage::nowa_gra_B)
	{
		this->poprzedniEtap = this->etap;
		this->etap = Stage::rozstawienieGraczaA;
	}



	//Wcisniecie przycisku BACK
	if (this->buttons["BACK"]->isPressed())
		this->etap = Stage::start;

	//Przycisk powrot w tablicy wynikow i na koncu
	if (this->etap == Stage::tabela || this->etap == Stage::koniec)
		this->buttons["BACK"]->showButton();

	//Przycisk koniec na koncu
	if (this->etap == Stage::koniec)
	{
		this->buttons["END"]->changePos(this->window->getSize().x / 2 - 75, 480, "Koniec Gry");
		this->buttons["END"]->showButton();
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
		this->iloscTur++;
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
	case Stage::nowa_gra_A:
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			this->playerOne->setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->playerOne->setSelected(false);
		}
	}
	case Stage::nowa_gra_B:
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			this->playerTwo->setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->playerTwo->setSelected(false);
		}
	}
	case Stage::rozstawienieGraczaA:
	{
		this->graczA.updateBoard(this->mousePosView);
		this->updateText(&this->uiText, "Rozstawienie gracza " + this->graczA.getName() +", pozostalo statkow: " + std::to_string(this->graczA.getIloscUstawionych()));
		this->updateText(&this->playerName, "Plansza " + this->graczA.getName());
		this->updateText(&this->enemyName, "Plansza " + this->graczB.getName());

		if (this->graczA.getIloscUstawionych() == 0)
		{
			this->updateText(&this->uiText, "Zakonczono ustawianie statkow gracza " + this->graczA.getName() + ", zakoncz ture!");
			this->akcje = 0;
		}
	}
	break;
	case Stage::rozstawienieGraczaB:
	{
		this->graczB.updateBoard(this->mousePosView);
		this->updateText(&this->uiText, "Rozstawienie gracza " + this->graczB.getName() +", pozostalo statkow: " + std::to_string(this->graczB.getIloscUstawionych()));
		this->updateText(&this->playerName, "Plansza " + this->graczB.getName());
		this->updateText(&this->enemyName, "Plansza " + this->graczA.getName());
		if (this->graczB.getIloscUstawionych() == 0)
		{
			this->updateText(&this->uiText, "Zakonczono ustawianie statkow gracza " + this->graczB.getName() + ", zakoncz ture!");
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
			this->updateText(&this->playerName, "Plansza " + this->graczA.getName());
			this->updateText(&this->enemyName, "Plansza " + this->graczB.getName());
			if (!this->graczA.getAkcje())
				this->akcje = 0;

			if (this->graczB.czyKoniec())
			{
				this->stop = std::chrono::high_resolution_clock::now();

				this->etap = Stage::koniec;
			}

		}
		else
		{
			this->graczB.updateBoard(this->mousePosView, &graczA);
			this->updateText(&this->uiText, "Tura Gracz B");
			this->updateText(&this->playerName, "Plansza " + this->graczA.getName());
			this->updateText(&this->enemyName, "Plansza " + this->graczB.getName());
			if (!this->graczB.getAkcje())
				this->akcje = 0;


			if (this->graczA.czyKoniec())
			{
				this->stop = std::chrono::high_resolution_clock::now();

				this->etap = Stage::koniec;
			}

		}
	}
		break;
	case Stage::koniec:
	{

		if(this->graczA.czyPrzegral())
			this->updateText(&this->wynikGry, "Koniec gry, wygrywa gracz " + this->graczB.getName() + "!");
		else
			this->updateText(&this->wynikGry, "Koniec gry, wygrywa gracz " + this->graczA.getName() + "!");
		this->wynikGry.setPosition(this->window->getSize().x / 2 - this->wynikGry.getGlobalBounds().width / 2, 50);

		
		std::ostringstream out;
		out << std::chrono::duration<double>(this->stop - this->start).count();
		std::string time = (out.str()).substr(0, out.str().size() - 4) + "s";

		std::string result =
			"Podsumowanie gry: \nCzas gry: " + time + "\n"
			+ "Trafionych statkow przez gracza " + this->graczA.getName() + ": " + std::to_string(this->graczB.iloscTrafionych()) + "\n"
			+ "Trafionych statkow przez gracza " + this->graczB.getName() + ": " + std::to_string(this->graczA.iloscTrafionych()) + "\n"
			+ "Ilosc tur: " + std::to_string(this->iloscTur-1);

			;

		this->updateText(&this->gameResult, result);
		this->gameResult.setPosition(this->window->getSize().x / 2 - this->gameResult.getGlobalBounds().width / 2, 100);

		if (!this->czyZapisano)
		{
			saveGame(time, std::to_string(this->graczB.iloscTrafionych()), std::to_string(this->graczA.iloscTrafionych()), std::to_string(this->iloscTur - 1));
			this->czyZapisano = true;
		}

	}
		break;
	case Stage::tabela:
	{
		this->updateText(&this->wynikGry, "Tablica ostatnich 10 gier");

		loadGame();

	}
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
	{
		
	}
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

void Game::renderTextBox(sf::RenderTarget& target)
{
	if (this->etap == Stage::nowa_gra_A)
		this->playerOne->drawTo(*this->window);
	else if(this->etap == Stage::nowa_gra_B)
		this->playerTwo->drawTo(*this->window);
}

void Game::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(&target);
	}
	
}

void Game::saveGame(std::string czas, std::string iloscA, std::string iloscB, std::string iloscTur)
{
	std::ofstream myFile;
	myFile.open("GameResult.csv", std::ios::app);

	myFile << "Czas gry: " << czas << " ilosc zbitych " << this->graczA.getName() << ": " << iloscA << " ilosc zbitych " << this->graczB.getName() << ": " << iloscB << " ilosc tur: " << iloscTur << "\n";

	myFile.close();
}

void Game::loadGame()
{

	std::ifstream file("GameResult.csv");

	if (file.is_open())
	{
		std::string line;
		int i, j, lines;
		i = j = lines = 0;

		while (std::getline(file, line))
			lines++;

		file.clear();
		file.seekg(0, std::ios::beg);

		if(lines > 10)
			while (std::getline(file, line))
			{
				if (i < lines - 10)
				{
					i++;
					continue;
				}
				
				this->updateText(&this->gameResultTab[j], line);
				j++;
				i++;

			}
		else
		{
			i = 0;
			while (std::getline(file, line))
			{
				this->updateText(&this->gameResultTab[i], std::to_string(i+1) + ": " + line);
				i++;
			}

			for (i; i < 10; i++)
			{
				this->updateText(&this->gameResultTab[i], std::to_string(i+1) + ": ----Brak danych----");

			}
		}

		file.close();
	}


}
