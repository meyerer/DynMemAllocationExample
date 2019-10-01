/********************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the interface for the Game class it handles the input validation and
* combining the necessary functions into playGame for the main function to utilize. The 
* class has two Character pointers player1 and player2 to hold the different characters.
*******************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include "Character.hpp"

class Game
{
	private:
		std::string mainChoice;
		std::string charChoice;
		int mainMenuChoice;
		Character* player1;
		Character* player2;

	public:
		Game();
		void readMainMenu();
		void readSecondaryMenu();
		void readCharacterMenu();
		bool validateStartMenu();
		bool validateCharacterMenu(int);
		void allocateCharacter(int, int);
		void unallocMem();
		void playGame();
		int getMainMenu();
};

#endif
