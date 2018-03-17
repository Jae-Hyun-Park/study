#include "GameWindow.h"
void GameWindow::location() {
	player.locx = 1;            // 초기 플레이어 위치설정
	player2.locx = 2;
	return;
}

void GameWindow::gameSet() {         // 게임세팅 (각플레이어 캐릭터세팅, 맵세팅)
	player.charicterSet();
	player.status();
	player2.charicterSet();
	player2.status();
	cout << player.name << " vs " << player2.name << endl;
	cout << "■ = Wall, ♠ = " << player.name << ", ★ = " << player2.name << endl;
	map.ViewMap();
	cout << "\nBattle Start !!" << endl;
	return;
}

void GameWindow::gameRestart() {
	cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
	cin >> playstate;         // 재시작 확인
	player.interval();
	if (playstate == true) { // 재시작시 초기화
		turnstate1 = true;
		turnstate2 = false;
	}
	else
		return;
}

void GameWindow::gameStart() { // 게임진행
	while (1) {
		location();
		gameSet();
		while (playstate == true) {
			while (turnstate1 == true)
				playstate = player.turn(&player2.hp, &player2.def, &player2.locx, &turnstate1, &turnstate2, map.mapping);
			while (turnstate2 == true && playstate == true)
				playstate = player2.turn(&player.hp, &player.def, &player.locx, &turnstate2, &turnstate1, map.mapping);
		}
		gameRestart();
		if (playstate == false)
			return;
	}
}

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}
