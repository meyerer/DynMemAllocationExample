/************************************************************************************
**Author: Eric Meyer
**Date: 1 August 2019
**Description: This is the interface for the Blue Men class.  This class is
* a child class of character.  The functions below serve as a constructor and definition
* of the pure virtual functions declared in Character.
************************************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"


class BlueMen : public Character
{
	public:
		BlueMen();
		virtual int attack();
		virtual void defend(int);
		virtual void updateStrength(int);
};

#endif // 

