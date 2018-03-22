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
	virtual bool run(Character* player2, Character* Monster1, Character* Monster2, Map* map, item* Item1, item* Item2);
	virtual bool Warrior::turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, 
		Map* map, item* Item1, item* Item2);
	virtual ~Warrior();
};

