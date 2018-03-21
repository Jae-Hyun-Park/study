#include "Monster.h"

Monster::Monster(const char* _name, int _hp, int _mp, int _atk, int _def, int _range)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	hp = hpmax = _hp;
	mp = mpmax = _mp;
	atk = atkback = _atk;
	def = _def;
	range = _range;
}

bool Monster::attack(Character* player1, Character* player2, Map* map) {	// 어택 거리 체크
	cout << "attack! " << endl;
	for (int i = 1; i <= range; i++) {
		switch (map->mapping[locy + i][locx]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx - i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy - i][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
		switch (map->mapping[locy + i][locx + i]) {
		case 2:
			return playerAttack(player1, player2->name);
		case 3:
			return playerAttack(player2, player1->name);
		default:
			break;
		}
	}
	Sleep(500);
	cout << "No enemies in range" << endl;
	atkBuffSkill();
	return true;
}
bool Monster::playerAttack(Character* player1, const char* _name) {
	int damage = (atk - player1->def);
	if (damage > 0)
		player1->hp -= (atk - player1->def);
	else if (damage <= 0)            // 데미지가 0이하일경우 0으로처리
		damage = 0;
	Sleep(500);
	cout << player1->name << " " << damage << "Damage!" << endl;
	if (skillState == 1)   // 스킬발동 확인
		atkBack();
	return playerhpCheck(player1->name, player1->hp, _name);
}
bool Monster::playerhpCheck(const char* _name, int _hp, const char* _name2) { // 플레이어 hp체크
	if (_hp <= 0) {
		interval();
		cout << _name2 << " Win" << endl;
		interval();
		return false;
	}
	cout << _name << "'s Hp = " << _hp << endl;
	return true;
}
bool Monster::monsterturn(Character* player1, Character* player2, Map* map) {
	// 몬스터 턴 (상대플레이어 hp, def, location, 각 플레이어의 턴 상태변수, 맵)
	int turnMenu = GenerateRandom(1, 3);
	bool gameState = true; // 게임의 진행 확인
	interval();
	cout << name << "'s Turn!" << endl;

	switch (turnMenu) {
	case 1:
		Sleep(500);
		gameState = attack(player1, player2, map);
		return gameState;
	case 2:
		Sleep(500);
		atkBuffSkill();            // 스킬 성공시 턴을 넘김
		return gameState;
	case 3:
		rest();
		return gameState;
	default:
		break;
	}
}
bool Monster::atkBuffSkill() { // 어택버프
	if (skillState == 1) {
		cout << "Be activated Buff...." << endl;
		rest();
		return true;
	}
	else if (mp < 10) {
		cout << "Not enough MP" << endl;
		rest();
		return true;
	}
	atk += 10;
	mp -= 10;
	cout << "atkBuff! atk = " << atk << ", mp = " << mp << endl;
	skillState = 1;
	return false;
}

Monster::~Monster()
{
	if (name != NULL) {
		delete[] name;
		name = NULL;
	}
}
