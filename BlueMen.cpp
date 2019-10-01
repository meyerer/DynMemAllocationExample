/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Blue Men class.  Detailed descriptions
* of the functions are listed below.
************************************************************************************/

#include "BlueMen.hpp"
#include "Character.hpp"
#include <iostream>

/***************************************************************************
* This is the constructor of the Blue Men class.  It sets all key variables
* equal to the values detailed in the project prompt.
***************************************************************************/

BlueMen::BlueMen()
{
	armor = 3;
	strength = 12;
	attackDieNum = 2;
	defenseDieNum = 3;
	attackDieSide = 10;
	defenseDieSide = 6;
}

/*****************************************************************************
* This function serves as the definition of the attack function declared in
* Character for Blue Men.  The function is simple it declares a local attack
* number for this round and loops through the number of die, generating a
* random number between 1 and the sides on the attack die. The function
* returns attackNum so the defense function for the opposing character can
* calculate damage.
*****************************************************************************/

int BlueMen::attack()
{
	//variable to hold the attack roll
	int attackNum = 0;

	//loop through number of die
	for (int i = 0; i < attackDieNum; i++)
	{
		attackNum += rand() % attackDieSide + 1;
	}

	//print details of attack
	printAttackDetails("Blue Men", attackNum);

	//return attack num for defense
	return attackNum;

}

/*****************************************************************************
* This function serves as the definition for the defend function declared in
* Character for Blue Men.  It receives attackNum as a parameter to help calc
* the local variable damage.  Additionally, there is a local variable to keep
* track of the number the defense function 'rolled' (randomly generated).
* The function loops through the number of defense die then randomly generates a
* number between 1 and the sides on the defense die. The function checks if
* defense is less than zero, if so it sets defense to zero.  Then displays
* details of the damage calculations. Additionally it calls the update
* strength function to make sure strength is updated with the damage change.
*****************************************************************************/

void BlueMen::defend(int attackNum)
{
	//local variable for damage calc
	int damage = 0;
	//variable to track the defense roll
	int defenseNum = 0;

	//loop through the number of defense die
	for (int i = 0; i < defenseDieNum; i++)
	{
		defenseNum += rand() % defenseDieSide + 1;
	}

	//calculate damage
	damage = attackNum - defenseNum - armor;

	//check if damage is less than zero
	if (damage < 0)
	{
		damage = 0;
	}

	//print details of function
	printDamageDetails("Blue Men", armor, strength, defenseNum, attackNum, damage);

	//call for update strength
	updateStrength(damage);
}

/********************************************************************************
* This is the updateStrength function for Blue Men.  It receives an integer for
* damage and prints the details of the strength update.  Then updates the Blue Men
* strength variable.  A unique feature of Blue Men is that they lose a defense 
* die for every decrease of 4 strength points. The below function reflects that.
*********************************************************************************/

void BlueMen::updateStrength(int damage)
{
	//print details of the strength update
	printStrengthDetails("Blue Men", strength, damage);

	//Update Blue Men strength
	strength -= damage;

	//Checks first loss of die
	if (strength == 8)
	{
		defenseDieNum--;
	}
	//Checks second loss of die
	else if (strength == 4)
	{
		defenseDieNum--;
	}
}