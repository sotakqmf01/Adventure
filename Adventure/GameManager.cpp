#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Slime.h"
#include "Orc.h"
#include "Item.h"
#include "GenerateRandomNumber.h"

string GameManager::createCharacter()
{
	string name;
	cout << "============================================" << endl;
	cout << "            환영합니다. 모험가님!\n";
	cout << "============================================" << endl;
	cout << " 캐릭터명을 입력하세요 : ";
	getline(cin, name);			// 이름이 공백이면 다시 입력하도록하는 부분 나중에 추가?
	cout << endl;

	Character* player = Character::getInstance(name);
	cout << "        ** 캐릭터 [" << name << "] 생성 완료! **" << endl;
	player->displayStatus();

	return name;
}

Monster* GameManager::generateMonster(int level)
{
	Monster* monster = nullptr;

	switch (generateRandomNumber(0, 1)) {
	case 0:
		monster = new Slime(level);
		break;
	case 1:
		monster = new Orc(level);
		break;
	default:
		break;
	}

	return monster;
}

void GameManager::battle(Character* player)
{
	Monster* monster = generateMonster(player->getLevel());
	Sleep(2000);
	//system("cls");

	cout << "*************************************************" << endl;
	cout << "          " << monster->getName()
		<< " 발견 (HP:" << monster->getHealth() << ", DAMAGE:" << monster->getAttack() << ")" << endl;
	cout << "*************************************************" << endl;

	while (!player->isDead() && !monster->isDead()) {
		// 플레이어 -> 몬스터 공격
		cout << " " << player->getName() << "가(이) " << monster->getName() << "을(를) 공격!  ";
		monster->takeDamage(player->getAttack());

		// 몬스터가 죽으면 경험치와 골드 획득, 가끔 아이템도 드롭 + 전투 종료
		if (monster->isDead()) {
			// 아이템 드롭(몬스터) 및 아이템 획득(플레이어)
			cout << "-------------------------------------------------" << endl;
			Item* dropedItem = monster->dropItem();
			if (dropedItem != nullptr)
				player->getDropedItem(dropedItem);

			// 경험치 및 골드 획득
			int gainGold = randomGold();
			cout << ">> " << player->getName() << "가(이) 50EXP와 " << gainGold << " 골드를 획득" << endl;
			player->addExperience(50);
			player->addGold(gainGold);

			totalGold += gainGold;
			totalKilledMonster++;

			delete monster;
			break;
		}

		// 30% 확률로 아이템 사용 -> 그냥 useRandomItem에 확률적으로 사용하도록 할까?
		if (generateRandomNumber(1, 100) <= 30) {
			player->useRandomItem();
		}

		// 몬스터 -> 플레이어 공격
		cout << " " << monster->getName() << "가(이) " << player->getName() << "을(를) 공격!  ";
		player->takeDamage(monster->getAttack());

		// 플레이어가 죽으면 전투 종료
		if (player->isDead()) {
			break;
		}
	}
}

void GameManager::visitShop(Character* player)
{
	char visitShop;
	cout << "상점을 방문하시겠습니까? (Y/N) : ";
	cin >> visitShop;
	if (visitShop == 'y' || visitShop == 'Y') {

	}
}

int GameManager::randomGold()
{
	return generateRandomNumber(10, 20);
}

void GameManager::displayRPGResult()
{
	char lookResult;
	cout << "게임 결과를 보시겠습니까? (Y/N) : ";
	cin >> lookResult;
	if (lookResult == 'y' || lookResult == 'Y') {
		system("cls");
		cout << "=============게임 결과=============" << endl;
		cout << "> 몬스터 처치 수 : " << totalKilledMonster << endl;
		cout << "> 획득 골드량 : " << totalGold << endl;
		cout << "==================================" << endl;
	}
}
