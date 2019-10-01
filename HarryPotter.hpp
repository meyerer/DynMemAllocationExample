/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the interface for the Harry Potter class.  This class is
* a child class of character.  The functions below serve as a constructor and definition
* of the pure virtual functions declared in Character.
************************************************************************************/


#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"

class HarryPotter : public Character
{
	private:
		int numLives;

	public:
		HarryPotter();
		virtual int attack();
		virtual void defend(int);
		virtual void updateStrength(int);
};

#endif
