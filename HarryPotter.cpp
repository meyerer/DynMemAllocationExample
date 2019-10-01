/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Medusa class.  Detailed descriptions
* of the functions are listed below.
************************************************************************************/

#include "HarryPotter.hpp"
#include "Character.hpp"
#include <iostream>

/***************************************************************************
* This is the constructor of the Harry Potter class.  It sets all key variables
* equal to the values detailed in the project prompt.
***************************************************************************/

HarryPotter::HarryPotter()
{
	armor = 0;
	strength = 10;
	attackDieNum = 2;
	defenseDieNum = 2;
	attackDieSide = 6;
	defenseDieSide = 6;
	numLives = 1;
}

/*****************************************************************************
* This function serves as the definition of the attack function declared in
* Character for Harry Potter.  The function is simple it declares a local attack
* number for this round and loops through the number of die, generating a
* random number between 1 and the sides on the attack die. The function
* returns attackNum so the defense function for the opposing character can
* calculate damage.
*****************************************************************************/

int HarryPotter::attack()
{
	int attackNum = 0;

	for (int i = 0; i < attackDieNum; i++)
	{
		attackNum += rand() % attackDieSide + 1;
	}

	printAttackDetails("Harry Potter", attackNum);

	return attackNum;
}

/*****************************************************************************
* This function serves as the definition for the defend function declared in
* Character for Harry Potter.  It receives attackNum as a parameter to help calc
* the local variable damage.  Additionally, there is a local variable to keep
* track of the number the defense function 'rolled' (randomly generated).
* The function loops through the number of defense die then randomly generates a
* number between 1 and the sides on the defense die. The function checks if
* defense is less than zero, if so it sets defense to zero.  Then displays
* details of the damage calculations. Additionally it calls the update
* strength function to make sure strength is updated with the damage change.
*****************************************************************************/

void HarryPotter::defend(int attackNum)
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

	printDamageDetails("Harry Potter", armor, strength, defenseNum, attackNum, damage);

	updateStrength(damage);
}

/********************************************************************************
* This is the updateStrength function for Harry Potter.  It receives an integer for
* damage and prints the details of the strength update.  Then updates the Harry Potter
* strength variable. On of the unique details of Harry Potter is that he has more
* than one life, so when Harry dies the first time he comes back to live at 20
* strength.
*********************************************************************************/


void HarryPotter::updateStrength(int damage)
{
	printStrengthDetails("Harry Potter", strength, damage);

	strength -= damage;

	//Checks if harry died and has a life to lose
	if (strength <= 0 && numLives == 1)
	{
		//comes back to life at 20 strength
		strength = 20;
		numLives--;

		std::cout << std::endl;
		std::cout << "Harry Potter used Hogwarts!" << std::endl;
		std::cout << "Strength: " << strength << std::endl;
	}

}

