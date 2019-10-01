/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the implementation for the Barbarian class.  Detailed descriptions
* of the functions are listed below.
************************************************************************************/



#include "Barbarian.hpp"
#include "Character.hpp"
#include <iostream>

/***************************************************************************
* This is the constructor of the Barbarian class.  It sets all key variables
* equal to the values detailed in the project prompt.
***************************************************************************/
Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	attackDieNum = 2;
	defenseDieNum = 2;
	attackDieSide = 6;
	defenseDieSide = 6;

}

/*****************************************************************************
* This function serves as the definition of the attack function declared in
* Character for Barbarian.  The function is simple it declares a local attack
* number for this round and loops through the number of die, generating a 
* random number between 1 and the sides on the attack die. The function
* returns attackNum so the defense function for the opposing character can 
* calculate damage.
*****************************************************************************/
int Barbarian::attack()
{
	//local attack number variable
	int attackNum = 0;

	//loop through number of attack die
	for (int i = 0; i < attackDieNum; i++)
	{
		attackNum += rand() % attackDieSide + 1;
	}

	//print out results of attack
	printAttackDetails("Barbarian", attackNum);

	return attackNum;
}

/*****************************************************************************
* This function serves as the definition for the defend function declared in
* Character for Barbarian.  It receives attackNum as a parameter to help calc
* the local variable damage.  Additionally, there is a local variable to keep 
* track of the number the defense function 'rolled' (randomly generated).  
* The function loops through the number of defense die then randomly generates a
* number between 1 and the sides on the defense die. The function checks if 
* defense is less than zero, if so it sets defense to zero.  Then displays
* details of the damage calculations. Additionally it calls the update
* strength function to make sure strength is updated with the damage change.
*****************************************************************************/

void Barbarian::defend(int attackNum)
{
	//local damage and defense number
	int damage = 0;
	int defenseNum = 0;

	//loop through die
	for (int i = 0; i < defenseDieNum; i++)
	{
		defenseNum += rand() % defenseDieSide + 1;
	}

	//calculate damage
	damage = attackNum - defenseNum - armor;

	//check for negative damage
	if (damage < 0)
	{
		damage = 0;
	}

	//print details of function call
	printDamageDetails("Barbarian", armor, strength, defenseNum, attackNum, damage);

	//update strength
	updateStrength(damage);
}

/********************************************************************************
* This is the updateStrength function for Barbarian.  It receives an integer for 
* damage and prints the details of the strength update.  Then updates the Barbarian
* strength variable.
*********************************************************************************/

void Barbarian::updateStrength(int damage)
{
	printStrengthDetails("Barbarian", strength, damage);

	strength -= damage;
}