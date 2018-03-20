#pragma once

class item
{
public:

	char* name;
	int plusAtk;
	int plusDef;
	item(const char* _name, int _atk, int _def);

	virtual ~item();
};

