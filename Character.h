#pragma once
#include <iostream>
#include "Map.h"

using namespace std;

class Character {
private:                                    // 플레이어 정보(이름, 직업, 최대채력, 최대마나, 공격력, 사거리)
	int hpmax;
	int mpmax;
	int atkback;
	int range;
	bool skillState = 0;                     // 버프발동 상태 확인변수

public: 
	char* name;                                // 현재 정보(현재채력, 현재마나, 현재공격력, 방어력, 현재위치)
	char* job;
	int hp;                                         
	int mp; 
	int atk;
	int def;
	int locx;
	int locy;
	
	Character();                              // 플레이어 설정(이름, 직업)
	void status();                         // 플레이어 스테이터스
	void Warrior(const char* jobname);
	void Lancer(const char* jobname);
	bool run(int* _locx, int* _locy, Map* map);
	bool attack(int* _hp, int* _def);        // 공격함수
	bool atkBuffSkill();                     // 공격버프스킬함수
	void atkBack();                          // 버프스킬해제함수
	void rest();                             // 휴식함수
	bool hpCheck(int* _hp);                     // hp체크함수
	bool turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map);   // 각 플레이어 턴의 행동함수
	void interval();                          // 구분선
	void errorMessage();                       // 에러메세지 출력
	~Character();
};

