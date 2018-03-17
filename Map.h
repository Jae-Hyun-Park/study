#pragma once
#include <iostream>

using namespace std;

class Map {
private:                    
	char maps[10][21];       // View용 맵 배열
	char* pMap = maps[0];
	char* wall = "■";                 // 맵 리소스 (벽, 길, 각플레이어)
	char* road = "□";
	char* player1 = "♠";
	char* player2 = "★";

public:
	__int8 mapping[10][10] = {                    // 매핑
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 3, 0, 0, 0, 0, 0, 0, 4, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	void buildMapping();         // 맵초기화함수
	void ViewMap();              // 맵보기함수
	Map();
	~Map();
};

