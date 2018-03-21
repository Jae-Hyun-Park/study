#include "Map.h"

Map::Map() {
}
void Map::buildMapping() {  // 맵 초기화
	cout << "■ = Wall, ♠ = You, ★ = EnemyPlayer, ☆ = Goblin, ★ = Oak" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			switch (mapping[i][j]) {
			case 0:
				strcpy(pMap, road);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;

			case 1:
				strcpy(pMap, wall);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;

			case 2:
				strcpy(pMap, player1);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;

			case 3:
				strcpy(pMap, player2);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;

			case 4:
				strcpy(pMap, monster1);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;

			case 5:
				strcpy(pMap, monster2);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
				break;
			case 6:
				strcpy(pMap, item);
				pMap += 2;
				if (pMap == &maps[i][20])
					pMap++;
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

void Map::playerLocChecking(int _plocx1, int _plocy1, int _plocx2, int _plocy2, int _mlocx1, int _mlocy1, int _mlocx2, int _mlocy2, int _mhp1, int _mhp2) {          // 플레이어 위치체크
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapping[i][j] == 2 || mapping[i][j] == 3)
				mapping[i][j] = 0;
		}
	}
	mapping[_plocy1][_plocx1] = 2;
	mapping[_plocy2][_plocx2] = 3;
	mapping[_mlocy1][_mlocx1] = 4;
	mapping[_mlocy2][_mlocx2] = 5;
	if (_mhp1 <= 0)
		mapping[_mlocy1][_mlocx1] = 0;
	if (_mhp2 <= 0)
		mapping[_mlocy2][_mlocx2] = 0;
}

Map::~Map()
{
}
