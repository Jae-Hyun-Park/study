#include "Character.h"

Character::Character() {
	int jobNumber = 0;
	locx = 0;
	locy = 0;

	name = new char[1];

	cout << "name = ";
	cin >> name;
	while (true) {
		cout << "select Job (1. Warrior // 2. Lancer) ";

		cin >> jobNumber;
		switch (jobNumber)
		{
		case 1:
			Warrior("Warrior");
			interval();
			status();
			return;
		case 2:
			Lancer("Lancer");
			interval();
			status();
			return;
		default:
			errorMessage();
			interval();
			break;
		}
	}
}
Character::Character(const Character &player) {

	name = new char[1];
	name = player.name;
	if(player.range == 1){
			Lancer("Lancer");
			interval();
			status();
			return;
	}
	else if (player.range == 2) {
		Warrior("Warrior");
		interval();
		status();
		return;
	}
}
void Character::interval() {     // 구분선
	cout << "==============================================================" << endl;
}
void Character::errorMessage() { //에러메세지 출력
	cout << "error! Please enter the correct Number!" << endl;
	return;
}
bool Character::hpCheck(int* _hp) { // hp체크
	if (*_hp <= 0) {
		interval();
		cout << name << " Win" << endl;
		interval();
		return false;
	}
	cout << "enemy's Hp = " << *_hp << endl;
	return true;
}
bool Character::attack(int* _hp, int* _def) {	// 어택
	cout << "attack! " << endl;
	int damage = (atk - *_def);
	if (damage > 0)
		*_hp -= (atk - *_def);
	else if (damage <= 0)            // 데미지가 0이하일경우 0으로처리
		damage = 0;
	cout << damage << "Damage!" << endl;
	if (skillState == 1)   // 스킬발동 확인
		atkBack();
	return hpCheck(_hp);
}
bool Character::atkBuffSkill() { // 어택버프
	if (skillState == 1) {
		cout << "Be activated Buff...." << endl;
		return true;
	}
	else if (mp < 10) {
		cout << "Not enough MP" << endl;
		return true;
	}
	atk += 10;
	mp -= 10;
	cout << "atkBuff! atk = " << atk << ", mp = " << mp << endl;
	skillState = 1;
	return false;
}
void Character::atkBack() { // 버프제거함수	
	atk = atkback;
	skillState = 0;
	return;
}
void Character::status() { // 스테이터스
	interval();
	cout << "name = " << name << "\nJob = " << job << "\nhp = " << hp << " / " << hpmax
		<< "\nmp = " << mp << " / " << mpmax << "\natk = " << atk << "\ndef = " << def
		<< "\nlocx = " << locx << ", locy = " << locy << endl;
	interval();
	return;
}
void Character::Warrior(const char* jobname) {     // 전사
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
	return;
}
void Character::Lancer(const char* jobname) {   // 랜서
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 45;
	hp = hpmax;
	mpmax = 20;
	mp = mpmax;
	atkback = 17;
	atk = atkback;
	def = 7;
	range = 2;
	return;
}
void Character::rest() { // 휴식
	if (hp < hpmax) {
		hp += 5;
		if (hp > hpmax)
			hp = hpmax;
		cout << "Hp recovery " << hp << " / " << hpmax << endl;
	}
	if (mp < mpmax) {
		mp += 5;
		if (mp > mpmax)
			mp = mpmax;
		cout << "Mp recovery " << hp << " / " << hpmax << endl;
	}
	return;
}
bool Character::run(int* _locx, int* _locy, Map* map) {  // 이동
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left // 3. Up  // 4. Down)" << endl;
	cin >> goingNumber;

	switch (goingNumber) {
	case 1:
		locx++;
		if (locx == *_locx && locy == *_locy) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same locxation!)" << endl;
			locx--;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                 // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locx--;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 2:
		locx--;
		if (locx == *_locx && locy == *_locy) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same locxation!)" << endl;
			locx++;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                     // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locx++;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 3:
		locy--;
		if (locx == *_locx && locy == *_locy) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same locxation!)" << endl;
			locy++;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                      // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locy++;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	case 4:
		locy++;
		if (locx == *_locx && locy == *_locy) {                  // 위치 체킹 이동한 장소가 적과 동일위치면 이동취소후 메뉴로
			cout << "Can not Move! (Same locxation!)" << endl;
			locy--;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                       // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locy--;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Character::turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map) {
	// 플레이어 턴 (상대플레이어 hp, def, location, 각 플레이어의 턴 상태변수, 맵)
	int turnMenu = 0;
	bool locxationState = true;
	bool gameState = true; // 게임의 진행 확인
	interval();
	cout << name << "'s Turn!" << endl;
	cout << "1. attack // 2. skill // 3. rest // 4. run // 5. status // 6. View Map" << endl;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		if (abs(locx - *_locx) > range) {            // 사거리체크
			cout << "Not enough Range" << endl;
			*turnState1 = true;
			*turnState2 = !(*turnState1);
			return gameState;
		}
		gameState = attack(_hp, _def);
		break;
	case 2:
		*turnState1 = atkBuffSkill();            // 스킬 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		rest();
		break;
	case 4:
		*turnState1 = run(_locx, _locy, map);                // 이동 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		status();
		*turnState1 = true;                         // 스테이터스 확인 (턴을 넘기지 않음)
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
		map->playerLocChecking(locx, locy, *_locx, *_locy);
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
	*turnState1 = false;
	*turnState2 = !(*turnState1);
	return gameState;
}
Character::~Character()
{
	delete (name);
	delete (job);
}
