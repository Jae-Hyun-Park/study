#pragma once

enum itemType {
	Sword,
	Armmor
};
class item
{
public:

	itemType type;
	char* name;
	int plusAtk;
	int plusDef;
	int locx;
	int locy;

	item(const char* _name, itemType _type, int _atk, int _def, int _locx, int _locy);
	virtual ~item();
};

