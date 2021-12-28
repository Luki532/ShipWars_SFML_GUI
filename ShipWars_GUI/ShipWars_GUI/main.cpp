#include <iostream>

#include "Game.h"

int main()
{
	//OKNO GRY
	Game game;

	//GAME LOOP
	while (game.running())
	{
		//UPDATE
		game.update();

		//RENDER
		game.render();
	}

	return 0;
}