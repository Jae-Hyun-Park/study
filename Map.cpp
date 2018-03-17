#include "Map.h"

Map::Map() {
}
void Map::buildMapping() {  // ∏  √ ±‚»≠
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

void Map::ViewMap() {   // ∏ ∫∏±‚
	buildMapping();
	return;
}

Map::~Map()
{
}
