#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Slime.h"
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"
#include "BossMonster.h"
#include "Item.h"
#include "GenerateRandomNumber.h"

void GameManager::textColor(unsigned short color)	// 컬러 텍스트 함수 0(검은색)~15(밝은 하얀색)까지 입력
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void GameManager::printIntro()
{
	textColor(12);
	cout << "_________";
	textColor(7);
	cout << " ______     __    ______     ";
	textColor(9);	
	cout << "_______  ______            _______  _       _________          _______  _______ " << endl;
	textColor(12);
	cout << "\\__   __/";
	textColor(7);
	cout << "(  __  \\   /__\\  (  __  \\   "; 
	textColor(9); 
	cout << "(  ___  )(  __  \\ |\\     /|(  ____ \\( (    /|\\__   __/|\\     /|(  ____ )(  ____ \\" << endl;
	textColor(12);
	cout << "   ) (   ";
	textColor(7); 
	cout << "| (  \\  ) ( \\/ ) | (  \\  )  ";
	textColor(9); 
	cout << "| (   ) || (  \\  )| )   ( || (    \\/|  \\  ( |   ) (   | )   ( || (    )|| (    \\/" << endl;
	textColor(12);
	cout << "   | |   ";
	textColor(7); 
	cout << "| |   ) |  \\  /  | |   ) |  "; 
	textColor(9); 
	cout << "| (___) || |   ) || |   | || (__    |   \\ | |   | |   | |   | || (____)|| (__    " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| |   | |  /  \\/\\| |   | |  ";
	textColor(9); 
	cout << "|  ___  || |   | |( (   ) )|  __)  | (\\ \\) |   | |   | |   | ||     __) | __)   " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| |   ) | / /\\  /| |   ) |  "; 
	textColor(9); 
	cout << "| (   ) || |   ) | \\ \\_/ / | (      | | \\   |   | |   | |   | || (\\ (   | (      " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| (__/  )(  \\/  \\| (__/  )  "; 
	textColor(9); 
	cout << "| )   ( || (__/  )  \\   /  | (____/\\| )  \\  |   | |   | (___) || ) \\ \\__| (____/\\" << endl;
	textColor(12);
	cout << "   )_(   "; 
	textColor(7); 
	cout << "(______/  \\___/\\/(______/   "; 
	textColor(9); 
	cout << "|/     \\|(______/    \\_/   (_______/|/    )_)   )_(   (_______)|/   \\__/(_______/" << endl;
	textColor(7);
	Sleep(3000);
}

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

	switch (generateRandomNumber(0, 3)) {
	case 0:
		monster = new Slime(level);
		break;
	case 1:
		monster = new Orc(level);
		break;
	case 2:
		monster = new Goblin(level);
		break;
	case 3:
		monster = new Troll(level);
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
