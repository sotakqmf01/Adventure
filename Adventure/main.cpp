#include <iostream>
#include <cstdlib>
#include <windows.h>		// 캐릭터 생성 시 약간 시간 걸리는 것처럼 보이기 위해 Sleep(1500) 사용하기 위해 
#include "Character.h"
#include "GameManager.h"
using namespace std;

int main() {
	GameManager gameManager;

	// 1. 캐릭터 생성 - createCharacter()
	string name = gameManager.createCharacter();
	Character* player = Character::getInstance(name);

	// 2. 전투
	while (!player->isDead()) {
		gameManager.battle(player);
		player->displayStatus();
	}

	// 3. 상점 들릴꺼니?
	//gameManager.vishtShop(player);

	// 4. 캐릭터 사망 시 게임 종료
	// 게임 종료 시 결과 출력
	if (player->isDead()) {
		char lookResult;
		cout << "게임 결과를 보시겠습니까? (Y/N) : ";
		cin >> lookResult;
		if (lookResult == 'y' || lookResult == 'Y') {
			system("cls");
			cout << "=============게임 결과=============" << endl;
			cout << "> 몬스터 처치 수 : " << gameManager.totalKilledMonster << endl;
			cout << "> 획득 골드량 : " << gameManager.totalGold << endl;
			cout << "==================================" << endl;
		}
	}

	return 0;
}