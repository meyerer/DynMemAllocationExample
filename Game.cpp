/********************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Game class.  Detailed descriptions are listed
* below.
*******************************************************************************************/

#include "Game.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>
#include <sstream>

/************************************************************
* This function is a constructor for Game.  It initializes the
* string choice functions.
*************************************************************/
Game::Game()
{
	mainChoice = "";
	charChoice = "";
}

/*********************************************************************************
* This is the Menu prompt for the main menu.  It reads input from the user
* as a string and continues to prompt the user while validateStartMenu returns
* false (invalid input).
***********************************************************************************/

void Game::readMainMenu()
{
	//Prompt user for input while invalid input is present
	do
	{
		std::cout << "Welcome to Fantasy Island: Combat Edition!" << std::endl;
		std::cout << "Please choose an option below." << std::endl;
		std::cout << "1. Engage in Mortal Combat" << std::endl;
		std::cout << "2. Quit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> mainChoice;
		std::cout << std::endl;
	} while (!validateStartMenu());
}

/*********************************************************************************
* This is the secondary Menu prompt for the user to play again.  It reads input from 
* the user as a string and continues to prompt the user while validateStartMenu returns
* false (invalid input).
***********************************************************************************/

void Game::readSecondaryMenu()
{
	//Prompt user for input while invalid input is present
	do
	{
		std::cout << std::endl;
		std::cout << "1. Play again?" << std::endl;
		std::cout << "2. Quit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> mainChoice;
		std::cout << std::endl;
	} while (!validateStartMenu());
	
}


/*********************************************************************************
* This is the character Menu prompt for the user select characters.  It reads input from
* the user as a string and continues to prompt the user while validateCharacterMenu returns
* false (invalid input).  This function sends the character number so the validate
* character function can send the correct character to the allocate function to
* initialize players 1 and 2 to the right character
***********************************************************************************/


void Game::readCharacterMenu()
{
	//loop through both characters
	for (int character = 1; character <= 2; character++)
	{
		//Prompt user for input while invalid input is present
		do
		{
			std::cout << "Please select a character below for Player " << character << "!" << std::endl;
			std::cout << "1. Barbarian" << std::endl;
			std::cout << "2. Vampire" << std::endl;
			std::cout << "3. Blue Men" << std::endl;
			std::cout << "4. Medusa" << std::endl;
			std::cout << "5. Harry Potter" << std::endl;
			std::cout << "Choice: "; 
			std::cin >> charChoice;
			std::cout << std::endl;
		} while (!validateCharacterMenu(character));
	}
}

/**************************************************************************************************
* This function validates the start menu input.  It checks if the string is all integers
* If so it converts the string to integers using the sstream library.  It then sets mainMenuChoice
* to convertedInt for the main.cpp function. It returns a bool for the read function.
*****************************************************************************************************/

bool Game::validateStartMenu()
{

	//valid choice flag
	bool validChoice = false;
	//Integer variable to hold the converted string choice to integer
	int convertedInt;
	//accumulation variable for whether string values are integers
	int isInt = 0;

	//Step through values in string to determine whether values are integers
	//uses isdigit() function from cctype
	for (int i = 0; i < mainChoice.size(); i++)
	{
		if (isdigit(mainChoice[i]))
		{
			isInt++;
		}
	}

	//If choice is all ints
	if (isInt == mainChoice.size())
	{
		//use stringstream object to convert choice to integer
		std::stringstream str_stream_object(mainChoice);
		str_stream_object >> convertedInt;

		mainChoice = "";

		
		//checks range
		if (convertedInt < 1 || convertedInt > 2)
		{
			std::cout << "Please enter a valid menu option!" << std::endl;
		}
		//sets mainMenuChoice if valid
		else
		{
			mainMenuChoice = convertedInt;
			validChoice = true;
		}
	}
	//invalid user input
	else
	{
		std::cout << std::endl;
		std::cout << "Please enter a valid integer!" << std::endl;
	}

	return validChoice;
}

/**************************************************************************************************
* This function validates the start menu input.  It checks if the string is all integers
* If so it converts the string to integers using the sstream library.  It sends the character 
* number it receives as a parameter and the convertedInt to allocateCharacters to
* assign the values of player1 and player2 .It returns a bool for
* the read function.
*****************************************************************************************************/


bool Game::validateCharacterMenu(int character)
{
	//valid choice flag
	bool validChoice = false;
	//Integer variable to hold the converted string choice to integer
	int convertedInt;
	//accumulation variable for whether string values are integers
	int isInt = 0;

	//Step through values in string to determine whether values are integers
	//uses isdigit() function from cctype
	for (int i = 0; i < charChoice.size(); i++)
	{
		if (isdigit(charChoice[i]))
		{
			isInt++;
		}
	}

	//If choice is all ints
	if (isInt == charChoice.size())
	{
		//use stringstream object to convert choice to integer
		std::stringstream str_stream_object(charChoice);
		str_stream_object >> convertedInt;

		charChoice = "";

		//checks range
		if (convertedInt < 1 || convertedInt > 6)
		{
			std::cout << "Please enter a valid menu option!" << std::endl;
		}
		//if valid send to allocate character
		else
		{
			allocateCharacter(convertedInt,character);
			validChoice = true;
		}
	}
	//invalid input
	else
	{
		std::cout << std::endl;
		std::cout << "Please enter a valid integer!" << std::endl;
	}

	return validChoice;

}

/**************************************************************************
* This function essentially allocates player 1 and player 2 to the user's
* specifications. It receieves the character number for the choice and 
* character they chose. Both are ints
***************************************************************************/

void Game::allocateCharacter(int convertedInt, int character)
{
	//Checks if player 1
	if (character == 1)
	{
		//allocate player 1
		if (convertedInt == 1)
		{
			player1 = new Barbarian;
		}
		else if (convertedInt == 2)
		{
			player1 = new Vampire;
		}
		else if (convertedInt == 3)
		{
			player1 = new BlueMen;
		}
		else if (convertedInt == 4)
		{
			player1 = new Medusa;
		}
		else
		{
			player1 = new HarryPotter;
		}
	}
	//Checks if player2
	else
	{
		//allocate player 2
		if (convertedInt == 1)
		{
			player2 = new Barbarian;
		}
		else if (convertedInt == 2)
		{
			player2 = new Vampire;
		}
		else if (convertedInt == 3)
		{
			player2 = new BlueMen;
		}
		else if (convertedInt == 4)
		{
			player2 = new Medusa;
		}
		else
		{
			player2 = new HarryPotter;
		}
	}
}

//unallocates memory for player 1 and 2
//No parameters no return type
void Game::unallocMem()
{
	delete player1;
	player1 = 0;

	delete player2;
	player2 = 0;
}

/*****************************************************************************
* This function plays the game. It has local variables to hold the attack
* rolls to then send to the defense functions and keeps track of the round.
* It reads the Character menu then plays until one of the characters dies
* it then reports the winner.  Upon conclusion it asks to play again and 
* unallocates the memory for player 1 and 2 regardless.
*****************************************************************************/
void Game::playGame()
{
	//hold attack rolls
	int p1Attack;
	int p2Attack;
	//round counter
	int round = 0;
	readCharacterMenu();

	//Play while characters are alive
	while (player1->isAlive() && player2->isAlive())
	{
		//ouput round details
		std::cout << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		round++;
		std::cout << "Round " << round << ":" << std::endl;

		//player 1 roll
		std::cout << "Player 1 ATTACK: " << std::endl;
		p1Attack = player1->attack();
		std::cout << "Player 2 DEFEND: " << std::endl;
		player2->defend(p1Attack);

		//player 2 roll
		std::cout << "Player 2 ATTACK: " << std::endl;
		p2Attack = player2->attack();
		std::cout << "Player 1 DEFEND: " << std::endl;
		player1->defend(p2Attack);

		std::cout << "-------------------------------------------------" << std::endl;
	}

	//Checks who won
	if (player1->isAlive())
	{
		std::cout << "Player 1 wins!" << std::endl;
	}
	else
	{
		std::cout << "Player 2 wins!" << std::endl;
	}

	//asks to play again
	readSecondaryMenu();
	//deletes dynamic memory
	unallocMem();

}

//returns mainMenuChoice for main.cpp
//no parameters no return type
int Game::getMainMenu()
{
	return mainMenuChoice;
}