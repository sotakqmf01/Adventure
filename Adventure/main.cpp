#include <iostream>
#include <cstdlib>
#include <windows.h>		// ĳ���� ���� �� �ణ �ð� �ɸ��� ��ó�� ���̱� ���� Sleep(1500) ����ϱ� ���� 
#include "Character.h"
#include "GameManager.h"
using namespace std;

// dev.gameManager test commit

int main() {
	GameManager gameManager;

	// 1. ĳ���� ���� - createCharacter()
	string name = gameManager.createCharacter();
	Character* player = Character::getInstance(name);

	// 2. ����
	while (!player->isDead()) {
		gameManager.battle(player);
		player->displayStatus();
	}
	//
	// pull request test ���� �׽�Ʈ
	// 
	// 3. ���� �鸱����?
	//gameManager.vishtShop(player);
	// 1234566778
	// 4. ĳ���� ��� �� ���� ����
	// ���� ���� �� ��� ���
	if (player->isDead()) {
		char lookResult;
		cout << "���� ����� ���ðڽ��ϱ�? (Y/N) : ";
		cin >> lookResult;
		if (lookResult == 'y' || lookResult == 'Y') {
			system("cls");
			cout << "=============���� ���=============" << endl;
			cout << "> ���� óġ �� : " << gameManager.totalKilledMonster << endl;
			cout << "> ȹ�� ��差 : " << gameManager.totalGold << endl;
			cout << "==================================" << endl;
		}
	}

	return 0;
}