/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the interface for the Character class.  This class is 
* the parent class for every character in the game. It has several integer variables
* to track the armor, strength, number of attack/defense die, number of attack/defense
* sides for each individual character.  Additionally it has a virtual function for
* attacks, defence, and update strength. Finally it has inherited functions to print
* details about the character and whether the character is alive.
************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>

class Character
{
	protected:
		int armor;
		int strength;
		int attackDieNum;
		int defenseDieNum;
		int attackDieSide;
		int defenseDieSide;

	public:	
		virtual int attack() = 0;
		virtual void defend(int) = 0;
		virtual void updateStrength(int) = 0;
		void printAttackDetails(std::string, int);
		void printDamageDetails(std::string, int, int, int, int, int);
		void printStrengthDetails(std::string, int, int);
		bool isAlive();
		
};

#endif // !CHARACTER_HPP

