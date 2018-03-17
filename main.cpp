#include "Character.h"

int main() {

	Character player, player2;

	bool turnstate1 = true; // player1의 턴 상태변수
	bool turnstate2 = false; // player2의 턴 상태변수
	bool playstate = true; // 게임의 상태변수 false = Gmae End

	player.loc = 0;            // 초기 플레이어 위치설정
	player2.loc = 2;

	while (1) {
		player.charicterSet();
		player.status();
		player2.charicterSet();
		player2.status();
		cout << player.name << " vs " << player2.name << endl; 
		cout << "\nBattle Start !!" << endl;
		while (playstate == true) {                 // 게임진행
			while (turnstate1 == true)
				playstate = player.turn(&player2.hp, &player2.def, &player2.loc, &turnstate1, &turnstate2);
			while (turnstate2 == true && playstate == true)
				playstate = player2.turn(&player.hp, &player.def, &player.loc, &turnstate2, &turnstate1);
		}
		cout << "game end \n restart? (1. restart // 0. Exit)" << endl;
		cin >> playstate;         // 재시작 확인
		player.interval();
		if (playstate == true) { // 재시작시 초기화
			turnstate1 = true;
			turnstate2 = false;
		}else
			return 0;
	}
}

//해야할것 : 맵추가(2차원배열 [10][10]정도로 만들어서 벽, 땅, 캐릭터위치 구현)