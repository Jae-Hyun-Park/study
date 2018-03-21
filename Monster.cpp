#include "Monster.h"

Monster::Monster(const char* _name, int _hp, int _mp, int _atk, int _def, int _range)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	hp = this->hpmax = _hp;
	mp = mpmax = _mp;
	atk = atkback = _atk;
	def = _def;
	range = _range;
}

bool Monster::isdead()
{
	return false;
}


Monster::~Monster()
{
	delete(name);
}
