#include "Warrior.h"



Warrior::Warrior(const char* jobname)
{
	name = new char[1];
	cout << "name = ";
	cin >> name;
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 60;
	hp = hpmax;
	mpmax = 30;
	mp = mpmax;
	atkback = 15;
	atk = atkback;
	def = 10;
	range = 1;
}

bool Warrior::dash() {
	if (dashskillState == 1) {
		cout << "Be activated Buff...." << endl;
		return true;
	}
	else if (mp < 5) {
		cout << "Not enough MP" << endl;
		return true;
	}
	speed++;
	mp -= 5;
	cout << "speedup!! speed = " << speed << ", mp = " << mp << endl;
	dashskillState = 1;
	return false;
}

void Warrior::speedBack() {
	speed--;
	dashskillState = 0;
	return;
}
bool Warrior::run(Character* player2, Character* Monster1, Character* Monster2, Map* map) {  // 이동
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left // 3. Up  // 4. Down)" << endl;
	cin >> goingNumber;

	switch (goingNumber) {
	case 1:
		locx += speed;
		if ((locx == player2->locx && locy == player2->locy) ||
			(locx == Monster1->locx && locy == Monster1->locy) ||
			(locx == Monster2->locx && locy == Monster2->locy)) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same location!)" << endl;
			locx -= speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                 // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locx -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) ||
			range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 2:
		locx -= speed;
		if ((locx == player2->locx && locy == player2->locy) ||
			(locx == Monster1->locx && locy == Monster1->locy) ||
			(locx == Monster2->locx && locy == Monster2->locy)) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same location!)" << endl;
			locx += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                     // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locx += speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) ||
			range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 3:
		locy -= speed;
		if ((locx == player2->locx && locy == player2->locy) ||
			(locx == Monster1->locx && locy == Monster1->locy) ||
			(locx == Monster2->locx && locy == Monster2->locy)) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same location!)" << endl;
			locy += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                      // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locy += speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) ||
			range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 4:
		locy += speed;
		if ((locx == player2->locx && locy == player2->locy) ||
			(locx == Monster1->locx && locy == Monster1->locy) ||
			(locx == Monster2->locx && locy == Monster2->locy)) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same location!)" << endl;
			locy -= speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                       // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locy -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) ||
			range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) ||
			range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)))
			cout << "Enemy Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Warrior::turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map) {
	// 플레이어 턴 (상대플레이어 hp, def, location, 각 플레이어의 턴 상태변수, 맵)
	int turnMenu = 0;
	bool locxationState = true;
	bool gameState = true; // 게임의 진행 확인
	interval();
	cout << name << "'s Turn!" << endl;
	cout << "1. attack // 2. attackskill 3, dashSkill // 4. rest // 5. run // 6. status // 7. View Map" << endl;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		gameState = attack(player2, Monster1, Monster2, map, turnState1, turnState2);
		return gameState;
	case 2:
		*turnState1 = atkBuffSkill();            // 스킬 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		*turnState1 = dash();            // 스킬 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 4:
		rest();
		*turnState1 = false;
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		*turnState1 = run(player2, Monster1, Monster2, map);                // 이동 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
		status();
		*turnState1 = true;                         // 스테이터스 확인 (턴을 넘기지 않음)
		*turnState2 = !(*turnState1);
		return gameState;
	case 7:
		map->playerLocChecking(locx, locy, player2->locx, player2->locy, Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->ViewMap();
		*turnState1 = true;                         // 맵 확인 (턴을 넘기지 않음)
		*turnState2 = !(*turnState1);
		return gameState;
	default:
		errorMessage();
		*turnState1 = true;
		*turnState2 = !(*turnState1);
		return gameState;
	}
}
Warrior::~Warrior()
{
	delete (job);
}
