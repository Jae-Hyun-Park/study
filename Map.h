#pragma once
#include <iostream>

using namespace std;
const int mapSize = 10;
class Map {
private:
	char maps[10][21];       // View용 맵 배열
	char* pMap = maps[0];
	char* wall = "■";                 // 맵 리소스 (벽, 길, 각플레이어)
	char* road = "□";
	char* player1 = "♠";
	char* player2 = "♣";
	char* monster1 = "☆";
	char* monster2 = "★";

public:
	__int8 mapping[mapSize][mapSize] = {                    // 매핑
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

	void buildMapping();         // 맵초기화함수
	void ViewMap();              // 맵보기함수
	void playerLocChecking(int _locx1, int _locy1, int _locx2, int _locy2);     // 플레이어 위치 체크

	Map();
	~Map();
};

