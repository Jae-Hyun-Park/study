#include "Map.h"

Map::Map() {
}
void Map::buildMapping() {  // 맵 초기화
	cout << "■ = Wall, ♠ = " << "You" << ", ★ = " << "Enemy" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mapping[i][j]) {
			case 1:
				strcpy(pMap, wall);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;
			
			case 0:
				strcpy(pMap, road);
				pMap += 2;
				break;

			case 3:
				strcpy(pMap, player1);
				pMap += 2;
				break;

			case 4:
				strcpy(pMap, player2);
				pMap += 2;
				break;

			default:
				break;
			}
		}
		cout << maps[i] << endl;
	}
	pMap = maps[0];
	return;
}

void Map::ViewMap() {   // 맵보기
	buildMapping();
	return;
}

void Map::playerLocChecking(int _locx1, int _locy1, int _locx2, int _locy2) {          // 플레이어 위치체크
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapping[i][j] == 3 || mapping[i][j] == 4)
				mapping[i][j] = 0;
		}
	}
	mapping[_locy1][_locx1] = 3;
	mapping[_locy2][_locx2] = 4;
}

Map::~Map()
{
}
