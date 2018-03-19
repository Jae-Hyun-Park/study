#pragma once
#include "Character.h"
#include "Map.h"
class GameWindow {
private:
	bool turnstate1 = true; // player1의 턴 상태변수
	bool turnstate2 = false; // player2의 턴 상태변수
	void location(Character* player, Character* player2);
	void gameSet(Character* player, Character* player2);
	void interval();

public:
	Map * map;
	void gameRestart();
	void gameStart(Map* map);
	bool playstate = true; // 게임의 상태변수 false = Gmae End

	GameWindow();
	~GameWindow();
};

