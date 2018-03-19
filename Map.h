#pragma once
#include <iostream>

using namespace std;

class Map {
private:                    
	char maps[10][21];       // View�� �� �迭
	char* pMap = maps[0];
	char* wall = "��";                 // �� ���ҽ� (��, ��, ���÷��̾�)
	char* road = "��";
	char* player1 = "��";
	char* player2 = "��";

public:
	__int8 mapping[10][10] = {                    // ����
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 1, 0, 1, 1, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	void buildMapping();         // ���ʱ�ȭ�Լ�
	void ViewMap();              // �ʺ����Լ�
	void playerLocChecking(int _locx1, int _locy1, int _locx2, int _locy2);     // �÷��̾� ��ġ üũ

	Map();
	~Map();
};
