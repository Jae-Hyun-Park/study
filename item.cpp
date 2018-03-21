#include "item.h"
#include <iostream>

item::item(const char* _name, itemType _type, int _atk, int _def, int _locx, int _locy) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	type = _type;
	plusAtk = _atk;
	plusDef = _def;
	locx = _locx;
	locy = _locy;
}

item::~item() {
	if (name != NULL) {
		delete[] name;
		name = NULL;
	}
}
