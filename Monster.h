#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	int hpmax;
	Monster(const char* _name, int _hp, int _mp, int _atk, int _def, int _range);
	bool isdead();
	virtual ~Monster();
};

