#pragma once
#include "Map.h"
#include "Warrior.h"
#include "Lancer.h"
#include "Monster.h"
#include "item.h"

class GameWindow {
private:
	bool turnstate1 = true; // player1의 턴 상태변수
	bool turnstate2 = false; // player2의 턴 상태변수
	void location(Character* player, Character* player2, Character* monster1, Character* monster2);
	void gameSet(Character* player, Character* player2);
	void interval();

public:
	Map * map;
	Monster* monster[2];
	Character* player[2];
	item* Item[2];

	void itemSet();
	void monsterSet();
	void gameRestart();
	void gameStart(Map* map);
	bool playstate = true; // 게임의 상태변수 false = Gmae End
	void errorMessage(); 

	GameWindow();
	~GameWindow();
};

