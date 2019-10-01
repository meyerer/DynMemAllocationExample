/********************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the main function for the Battle Game.  It declares a game object,
* asks the user if they want to play, and continues to play while they want to.
*********************************************************************************/

#include "Game.hpp"
#include <ctime>
#include <iostream>


int main()
{
	//seed random
	srand(time(NULL));

	//Game object
	Game game1;

	//ask to play
	game1.readMainMenu();

	//play while user wants to
	while (game1.getMainMenu() == 1)
	{
		game1.playGame();
	}
}