#pragma once
#include <iostream>
using namespace std;

class Character
{
private:
	char name[256];
	int hp;
	int mp;
	int sp;
	int atk;
	int def;
	int speed = 10;
	int hpmax = hp;
	int mpmax = mp;
	int spmax = sp;
	int atkback = atk;
	int skillCount = 0;
public:
	Character();
	void charicterSet();
	void viewCharacter();
	void run();
	void walk();
	void attack(int _hp, int _def);
	void atkBuffSkill();
	void atkBack();
	void rest();
	void hpCheck();
	~Character();
};

