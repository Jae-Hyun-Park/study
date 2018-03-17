#pragma once
#include "Character.h"
#include "Map.h"
class GameWindow {
private:
	bool turnstate1 = true; // player1의 턴 상태변수
	bool turnstate2 = false; // player2의 턴 상태변수
	bool playstate = true; // 게임의 상태변수 false = Gmae End

	void location();
	void gameSet();
	void gameRestart();

public:
	Character player, player2;
	Map map;
	void gameStart();
	GameWindow();
	~GameWindow();
};

