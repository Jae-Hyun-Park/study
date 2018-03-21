#include "GameWindow.h"

void GameWindow::interval() {     // 구분선
	cout << "==============================================================" << endl;
}
void GameWindow::location(Character* player, Character* player2, Character* monster1, Character* monster2) {
	player->locx = 4;      // 초기 플레이어, 몬스터 위치설정
	player->locy = 1;
	player2->locx = 8;
	player2->locy = 5;
	monster1->locx = 5;
	monster1->locy = 1;
	monster2->locx = 4;
	monster2->locy = 8;
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
			while (turnstate1 == true) {
			map->playerLocChecking(player[0]->locx, player[0]->locy, player[1]->locx, player[1]->locy,
				monster[0]->locx, monster[0]->locy, monster[1]->locx, monster[1]->locy, monster[0]->hp, monster[1]->hp);
			playstate = player[0]->turn(player[1], monster[0], monster[1], &turnstate1, &turnstate2, map);
			}
			while (turnstate2 == true && playstate == true) {
				map->playerLocChecking(player[1]->locx, player[1]->locy, player[0]->locx, player[0]->locy,
					monster[0]->locx, monster[0]->locy, monster[1]->locx, monster[1]->locy, monster[0]->hp, monster[1]->hp);
				playstate = player[1]->turn(player[0], monster[0], monster[1], &turnstate2, &turnstate1, map);
			}
			if (playstate == false)
				break;
			map->playerLocChecking(player[0]->locx, player[0]->locy, player[1]->locx, player[1]->locy,
				monster[0]->locx, monster[0]->locy, monster[1]->locx, monster[1]->locy, monster[0]->hp, monster[1]->hp);
			monster[0]->turn(player[1], monster[0], monster[1], &turnstate1, &turnstate2, map);
			map->playerLocChecking(player[0]->locx, player[0]->locy, player[1]->locx, player[1]->locy,
				monster[0]->locx, monster[0]->locy, monster[1]->locx, monster[1]->locy, monster[0]->hp, monster[1]->hp);
			monster[1]->turn(player[1], monster[0], monster[1], &turnstate1, &turnstate2, map);
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
		delete(monster[i]);
		player[i] = NULL;
		monster[i] = NULL;
	}
	delete(map);
}
