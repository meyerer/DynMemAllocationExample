/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Medusa class.  Detailed descriptions
* of the functions are listed below.
************************************************************************************/

#include "Medusa.hpp"
#include "Character.hpp"
#include <iostream>

/***************************************************************************
* This is the constructor of the Medusa class.  It sets all key variables
* equal to the values detailed in the project prompt.
***************************************************************************/

Medusa::Medusa()
{
	armor = 3;
	strength = 8;
	attackDieNum = 2;
	defenseDieNum = 1;
	attackDieSide = 6;
	defenseDieSide = 6;
}

/*****************************************************************************
* This function serves as the definition of the attack function declared in
* Character for Medusa.  The function is simple it declares a local attack
* number for this round and loops through the number of die, generating a
* random number between 1 and the sides on the attack die. The function
* returns attackNum so the defense function for the opposing character can
* calculate damage.  A unique feature of Medusa is if she rolls a 12 the other 
* opponent automatically dies.
*****************************************************************************/

int Medusa::attack()
{
	//variable for attack roll
	int attackNum = 0;

	//loop through attack die
	for (int i = 0; i < attackDieNum; i++)
	{
		attackNum += rand() % attackDieSide + 1;
	}

	//if medusa rolls a 12 
	//return a value more than any strength
	if (attackNum == 12)
	{
		attackNum = 100;

		std::cout << std::endl;
		std::cout << "Medusa used Charm!" << std::endl;
	}

	//print details of this function
	printAttackDetails("Medusa", attackNum);

	//return attackNum for defense
	return attackNum;

}

/*****************************************************************************
* This function serves as the definition for the defend function declared in
* Character for Medusa.  It receives attackNum as a parameter to help calc
* the local variable damage.  Additionally, there is a local variable to keep
* track of the number the defense function 'rolled' (randomly generated).
* The function loops through the number of defense die then randomly generates a
* number between 1 and the sides on the defense die. The function checks if
* defense is less than zero, if so it sets defense to zero.  Then displays
* details of the damage calculations. Additionally it calls the update
* strength function to make sure strength is updated with the damage change.
*****************************************************************************/

void Medusa::defend(int attackNum)
{
	int damage = 0;
	int defenseNum = 0;

	for (int i = 0; i < defenseDieNum; i++)
	{
		defenseNum += rand() % defenseDieSide + 1;
	}

	damage = attackNum - defenseNum - armor;

	if (damage < 0)
	{
		damage = 0;
	}

	printDamageDetails("Medusa", armor, strength, defenseNum, attackNum, damage);

	updateStrength(damage);
}

/********************************************************************************
* This is the updateStrength function for Medusa.  It receives an integer for
* damage and prints the details of the strength update.  Then updates the Medusa
* strength variable.
*********************************************************************************/


void Medusa::updateStrength(int damage)
{
	printStrengthDetails("Medusa", strength, damage);

	strength -= damage;
}