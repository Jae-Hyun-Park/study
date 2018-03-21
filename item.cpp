#include "item.h"
#include <iostream>

item::item(const char* _name, int _atk, int _def)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	plusAtk = _atk;
	plusDef = _def;
}

item::~item()
{
}
