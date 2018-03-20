#include "GameWindow.h"

void GameWindow::interval() {     // 구분선
	cout << "==============================================================" << endl;
}
void GameWindow::location(Character* player, Character* player2, Character* monster1, Character* monster2) {
	player->locx = 7;      // 초기 플레이어 위치설정
	player->locy = 5;
	player2->locx = 8;
	player2->locy = 5;
	monster1->locx = 1;
	monster1->locy = 5;
	monster2->locx = 8;
	monster2->locy = 4;
	return;
}
void GameWindow::errorMessage() { //에러메세지 출력
	cout << "error! Please enter the correct Number!" << endl;
	return;
}
void GameWindow::gameSet(Character* player, Character* player2) {         // 게임세팅
	cout << player->name << "(" << player->job << ")" << " vs " << player2->name << "(" << player2->job << ")" << endl;
	cout << "\nBattle Start !!" << endl;
	return;
}

void GameWindow::gameRestart() {
	cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
	cin >> playstate;         // 재시작 확인
	interval();
	if (playstate == true) { // 재시작시 초기화
		turnstate1 = true;
		turnstate2 = false;
	}
	else
		return;
}
void GameWindow::monsterSet() {
	monster[0] = new Monster("Goblin", 30, 0, 15, 5, 1);
	monster[1] = new Monster("Oak", 50, 10, 20, 10, 2);
}

void GameWindow::gameStart(Map* map) { // 게임진행
	while (true) {
		int jobNumber = 0;
		for (int i = 0; i < 2; i++) {
			cout << "select Job(1. Warrior // 2. Lancer) = ";
			cin >> jobNumber;
			switch (jobNumber) {
			case 1:
				player[i] = new Warrior("Warrior");
				interval();
				player[i]->status();
				break;
			case 2:
				player[i] = new Lancer("Lancer");
				interval();
				player[i]->status();
				break;
			default:
				errorMessage();
				i--;
				break;
			}
		}
		//Character* player = new Character(); 
	//	Character* player2 = new Character();
		//Character* player2 = new Character(*player);
		monsterSet();
		location(player[0], player[1], monster[0], monster[1]);
		gameSet(player[0], player[1]);
		while (playstate == true) {
			while (turnstate1 == true)
				playstate = player[0]->turn(&player[1]->hp, &player[1]->def, &player[1]->locx, &player[1]->locy,
					&turnstate1, &turnstate2, map);
			while (turnstate2 == true && playstate == true)
				playstate = player[1]->turn(&player[0]->hp, &player[0]->def, &player[0]->locx, &player[0]->locy,
					&turnstate2, &turnstate1, map);
		}
		gameRestart();
		if (playstate == false)
			return;
	}
}

GameWindow::GameWindow()
{
	map = new Map;
	gameStart(map);
}

GameWindow::~GameWindow()
{
	for (int i = 0; i < 2; i++) {
		delete(player[i]);
		delete(Monster[i]);
		player[i] = NULL;
		Monster[i] = NULL;
	}
	delete(map);
}
