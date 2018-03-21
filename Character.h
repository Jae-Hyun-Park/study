#pragma once
#include <iostream>
#include "Map.h"
#include <windows.h>
#include "item.h"
#include <random>

using namespace std;

static bool dropItem = false;

enum EquipSlot
{
	WeaponSlot,
	ArmorSlot,
};

class Character {
protected:                                    // 플레이어 정보(이름, 직업, 최대채력, 최대마나, 공격력, 사거리)
	int hpmax;
	int mpmax;
	int atkback;
	int range;
	bool skillState = 0;                     // 버프발동 상태 확인변수
	int speed = 1;

public:
	char* name;                                // 현재 정보(현재채력, 현재마나, 현재공격력, 방어력, 현재위치)
	char* job;
	int hp;
	int mp;
	int atk;
	int def;
	int locx;
	int locy;

	item* equipedItem[2];

	Character();                              // 플레이어 설정(이름, 직업)
	Character(const Character &player);         // 플레이어 2 설정 (동일이름, 다른직업)
	void status();                         // 플레이어 스테이터스
	virtual bool run(Character* player2, Character* Monster1, Character* Monster2, Map* map, item* Item1, item* Item2);
	virtual bool attack(Character* player2, Character* Monster1, Character* Monster2, Map* map, bool* turnState1, bool* turnState2);        // 공격함수
	virtual bool playerAttack(Character* player2);              // 플레이어 어택판정
	bool monsterAttack(Character* Monster1);              // 몬스터 어택판정
	virtual bool atkBuffSkill();                     // 공격버프스킬함수
	void atkBack();                          // 버프스킬해제함수
	void rest();                             // 휴식함수
	virtual bool playerhpCheck(const char* _name, int _hp);                     // 플레이어hp체크함수
	bool monsterhpCheck(Character* Monster);                     // 몬스터hp체크함수
	virtual bool turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map, item* Item1, item* Item2);   // 각 플레이어 턴의 행동함수
	void interval();                          // 구분선
	void errorMessage();                       // 에러메세지 출력
	void dropItemCheck(Map* map, Character* Monster);
	int GenerateRandom(int min, int max);
	void EquipItem(EquipSlot slot, item* Item);
	virtual ~Character();
};

