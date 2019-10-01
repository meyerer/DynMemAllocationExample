/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Character class.  The majority of
* the functions are defined within the child classes, but the functions below are the
* inherited functions that are non-specific to the type of character.
************************************************************************************/
#include "Character.hpp"


/***************************************************************
* The function returns true if the character is alive.  This is 
* used in playGame() in Game.cpp to determine whether to keep 
* playing.
****************************************************************/
bool Character::isAlive()
{
	bool isAlive = true;

	//checks if character is dead
	if (strength <= 0)
	{
		isAlive = false;
	}

	return isAlive;
}

/************************************************************************
*This function prints details about what the attacker rolls.  It receives
* a string of the attacker's name and the integer of the attacker's roll
* then prints out a message.
**************************************************************************/

void Character::printAttackDetails(std::string name, int attackRoll)
{
	std::cout << name << "'s attack rolled a " << attackRoll << "!" << std::endl;
}

/************************************************************************
*This function prints details about the defense.  It receives
* a string of the a defender's name and integers for armor, strength,
* defensive roll, the attacker's roll, and the damage done.  It takes these
* elements and formats a message detailing the defender's stats.
**************************************************************************/

void Character::printDamageDetails(std::string name, int armor, int strength, int defenseRoll, int attackRoll, int damage)
{
	std::cout << std::endl;
	std::cout << name << ": " << "Armor = " << armor << " Strength = " << strength;
	std::cout << std::endl;
	std::cout << name << "'s defense rolled a " << defenseRoll << "!" << std::endl;
	std::cout << "Total Damage Calculation: " << std::endl;
	std::cout << damage << " = " << attackRoll << " - " << defenseRoll << " - " << armor << std::endl;
}

/*******************************************************************************
*This function prints the final strength details.  It receives the name of the 
* defender, its starting strength and the damage it sustains.  It calculates
* the new strength locally and outputs the results.
*******************************************************************************/

void Character::printStrengthDetails(std::string name, int strength, int damage)
{
	//calculates new strength and outputs results
	int strength2 = strength - damage;

	std::cout << std::endl;
	std::cout << name << "'s Strength Update: " << std::endl;
	std::cout << strength2 << " = " << strength << " - " << damage << std::endl;
	std::cout << std::endl;
}