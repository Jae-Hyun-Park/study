#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster(const char* _name, int _hp, int _mp, int _atk, int _def, int _range);
	virtual bool attack(Character* player1, Character* palyer2, Map* map);
	virtual bool playerAttack(Character* player1, const char* _name);
	virtual bool playerhpCheck(const char* _name, int _hp, const char* _name2);
	virtual bool monsterturn(Character* player1, Character* player2, Map* map);
	virtual bool atkBuffSkill();
	virtual ~Monster();
};

