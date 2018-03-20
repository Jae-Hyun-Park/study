#pragma once
#include "Character.h"
class Warrior :
	public Character
{
private:
	bool dashskillState = false;
public:
	Warrior(const char* jobname);
	bool dash();
	void speedBack();
	virtual bool run(int* _locx, int* _locy, Map* map);
	virtual bool Warrior::turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map);
	virtual ~Warrior();
};

