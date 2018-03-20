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
bool Warrior::run(int* _locx, int* _locy, Map* map) {  // �̵�
	int goingNumber = 0;
	cout << "Where will you go? (1. Right // 2. Left // 3. Up  // 4. Down)" << endl;
	cin >> goingNumber;

	switch (goingNumber) {
	case 1:
		locx += speed;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locx -= speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                 // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 2:
		locx -= speed;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locx += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                     // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locx += speed;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 3:
		locy -= speed;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locy += speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                      // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy += speed;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	case 4:
		locy += speed;
		if (locx == *_locx && locy == *_locy) {                  // ��ġ üŷ �̵��� ��Ұ� ���� ������ġ�� �̵������ �޴���
			cout << "Can not Move! (Same locxation!)" << endl;
			locy -= speed;
			return true;
		}
		if (map->mapping[locy][locx] == 1) {                       // ��ġ üŷ �̵��� ��Ұ� ���̸� �̵������ �޴���
			cout << "Can not Move! (Wall)" << endl;
			locy -= speed;
			return true;
		}
		cout << "The distance between Your and the Enemy(x + y) = " << (abs(locx - *_locx) + abs(locy - *_locy)) << endl;
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->buildMapping();
		if (range >= (abs(locx - *_locx) + abs(locy - *_locy)))
			cout << "Attack Possible!" << endl;
		if (speed != 1) {
			speedBack();
		}
		return false;
	default:
		errorMessage();
		return true;
	}
}
bool Warrior::turn(int* _hp, int* _def, int* _locx, int* _locy, bool* turnState1, bool* turnState2, Map* map) {
	// �÷��̾� �� (����÷��̾� hp, def, location, �� �÷��̾��� �� ���º���, ��)
	int turnMenu = 0;
	bool locxationState = true;
	bool gameState = true; // ������ ���� Ȯ��
	interval();
	cout << name << "'s Turn!" << endl;
	cout << "1. attack // 2. attackskill 3, dashSkill // 4. rest // 5. run // 6. status // 7. View Map" << endl;
	cin >> turnMenu;

	switch (turnMenu) {
	case 1:
		if (abs(locx - *_locx) > range) {            // ��Ÿ�üũ
			cout << "Not enough Range" << endl;
			*turnState1 = true;
			*turnState2 = !(*turnState1);
			return gameState;
		}
		gameState = attack(_hp, _def);
		break;
	case 2:
		*turnState1 = atkBuffSkill();            // ��ų ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 3:
		*turnState1 = dash();            // ��ų ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
		break;
	case 4:
		rest();
		break;
	case 5:
		*turnState1 = run(_locx, _locy, map);                // �̵� ������ ���� �ѱ�
		*turnState2 = !(*turnState1);
		return gameState;
	case 6:
		status();
		*turnState1 = true;                         // �������ͽ� Ȯ�� (���� �ѱ��� ����)
		*turnState2 = !(*turnState1);
		return gameState;
	case 7:
		map->playerLocChecking(locx, locy, *_locx, *_locy);
		map->ViewMap();
		*turnState1 = true;                         // �� Ȯ�� (���� �ѱ��� ����)
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
Warrior::~Warrior()
{
	delete (job);
}