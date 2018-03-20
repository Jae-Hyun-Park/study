#include "Character.h"
Character::Character() {
	locx = 0;
	locy = 0;
}
Character::Character(const Character &player) {

	name = new char[1];
	name = player.name;
	/*if(player.range == 1){
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
	}*/
}
void Character::interval() {     // 구분선
	cout << "==============================================================" << endl;
}
void Character::errorMessage() { //에러메세지 출력
	cout << "error! Please enter the correct Number!" << endl;
	return;
}
bool Character::playerhpCheck(int _hp) { // 플레이어 hp체크
	if (_hp <= 0) {
		interval();
		cout << name << " Win" << endl;
		interval();
		return false;
	}
	cout << "enemy's Hp = " << _hp << endl;
	return true;
}
bool Character::monsterhpCheck(Character* Monster) { // hp체크
	if (Monster->hp <= 0) {
		cout << Monster->name << "'s Dead" << endl;
		return true;
	}
	cout << Monster->name << "'s Hp = " << Monster->hp << "/" << Monster->hpmax<< endl;
	return true;
}
bool Character::attack(Character* player2, Character* Monster1, Character* Monster2, Map* map, bool* turnState1, bool* turnState2) {	// 어택 거리 체크
	cout << "attack! " << endl;
	for (int i = 1; i <= range; i++) {
		switch (map->mapping[locy + i][locx]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5: 
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx - i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy][locx - i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx - i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx + i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy][locx + i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx + i]) {
		case 3:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return playerAttack(player2);
		case 4:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster1);
		case 5:
			*turnState1 = false;
			*turnState2 = !(*turnState1);
			return monsterAttack(Monster2);
		default:
			break;
		}
	}
	cout << "No enemies in range" << endl;
	*turnState1 = true;
	*turnState2 = !(*turnState1);
	return true;
}
bool Character::playerAttack(Character* player2) {
	int damage = (atk - player2->def);
	if (damage > 0)
		player2->hp -= (atk - player2->def);
	else if (damage <= 0)            // 데미지가 0이하일경우 0으로처리
		damage = 0;
	cout << player2->name << " " << damage << "Damage!" << endl;
	if (skillState == 1)   // 스킬발동 확인
		atkBack();
	return playerhpCheck(player2->hp);
}
bool Character::monsterAttack(Character* Monster1) {
	int damage = (atk - Monster1->def);
	if (damage > 0)
		Monster1->hp -= (atk - Monster1->def);
	else if (damage <= 0)            // 데미지가 0이하일경우 0으로처리
		damage = 0;
	cout << Monster1->name << " " << damage << "Damage!" << endl;
	if (skillState == 1)   // 스킬발동 확인
		atkBack();
	return monsterhpCheck(Monster1);
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
		<< "\nspeed = " << speed << "\nlocx = " << locx << ", locy = " << locy << endl;
	interval();
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
bool Character::run(Character* player2, Character* Monster1, Character* Monster2, Map* map) {  // 이동
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
		}else if (map->mapping[locy][locx] == 1) {                 // 위치 체킹 이동한 장소가 벽이면 이동취소후 메뉴로
			cout << "Can not Move! (Wall)" << endl;
			locx -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemyplayer(x + y) = " << (abs(locx - player2->locx) + abs(locy - player2->locy)) << endl;
		map->playerLocChecking(locx, locy, player2->locx, player2->locy , Monster1->locx, Monster1->locy, Monster2->locx, Monster2->locy, Monster1->hp, Monster2->hp);
		map->buildMapping();
		if (range >= (abs(locx - player2->locx) + abs(locy - player2->locy)) || 
			range >= (abs(locx - Monster1->locx) + abs(locy - Monster1->locy)) || 
			range >= (abs(locx - Monster2->locx) + abs(locy - Monster2->locy)))
			cout << "Enemy Attack Possible!" << endl;
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
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Character::turn(Character* player2, Character* Monster1, Character* Monster2, bool* turnState1, bool* turnState2, Map* map) {
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
		gameState = attack(player2, Monster1, Monster2, map, turnState1, turnState2);
		return gameState;
	case 2:
		*turnState1 = atkBuffSkill();            // 스킬 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
	case 3:
		rest();
		*turnState1 = false;
		*turnState2 = !(*turnState1);
		return gameState;
	case 4:
		*turnState1 = run(player2, Monster1, Monster2, map);                // 이동 성공시 턴을 넘김
		*turnState2 = !(*turnState1);
		return gameState;
	case 5:
		status();
		*turnState1 = true;                         // 스테이터스 확인 (턴을 넘기지 않음)
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
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
Character::~Character()
{
	delete (name);

}
