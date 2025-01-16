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
#include "Bandit.h"
#include "BossMonster.h"
#include "Item.h"
#include "GenerateRandomNumber.h"
#include "printMessage.h"
#include "Shop.h"
#include <conio.h>		// _getch() 로 입력대기 받기 위해서 필요함

string GameManager::createCharacter()
{
	string name;
	PrintMessage printMessage;

	while (1)
	{
		printMessage.askName();
		getline(cin, name);
		cout << endl;

		if (name.find_first_of(" \n~!@#$%^&*()_=-/,.\?;:\'\"[]{}<>", 0) != string::npos) {
			printMessage.gotoXY(44, 4);
			cout << "이름에는 특수문자가 들어갈 수 없습니다.";
			Sleep(1500);
		}
		else if (name.length() > 12) {
			printMessage.gotoXY(42, 4);
			cout << "이름이 너무 길어요! (이름은 최대 한글 6자리)";
			Sleep(1500);
		}
		else if (name.length() <= 1) {
			printMessage.gotoXY(42, 4);
			cout << "이름이 너무 짧아요! (이름은 최소 한글 1자리)";
			Sleep(1500);
		}
		else if (name == "nullptr") {
			printMessage.gotoXY(50, 4);
			cout << "해컨가?...";
			Sleep(1500);
		}
		else
		{
			break;
		}
	}
	Character* player = Character::getInstance(name);
	printMessage.afterName(name);
	
	return name;
}

Monster* GameManager::generateMonster(int level)
{
	Monster* monster = nullptr;

	switch (generateRandomNumber(0, 4))
	{
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
	case 4:
		monster = new Bandit(level);
		break;
	default:
		break;
	}

	return monster;
}

Monster* GameManager::generateBossMonster(int level)
{
	Monster* monster = new BossMonster(level);

	return monster;
}
void GameManager::countKilledMonster(string getname)
{
	string name = getname.substr(0, 4);
	if (name == "오크")
	{
		totalKilledOrc++;
	}
	else if (name == "고블")
	{
		totalKilledGoblin++;
	}
	else if (name == "슬라")
	{
		totalKilledSlime++;
	}
	else if (name == "산적")
	{
		totalKilledBandit++;
	}
	else if (name == "트롤")
	{
		totalKilledTroll++;
	}
	else 
	{
		totalKilledBoss++;
	}	 
}
void GameManager::battle(Character* player)
{
	Monster* monster = nullptr;
	PrintMessage printMessage;
	turnCounter = 1;

	if (player->getLevel() < 10)
	{
		// 일반 몬스터 소환
		monster = generateMonster(player->getLevel());
		Sleep(300);
	}
	else
	{
		// 보스 몬스터 소환
		monster = generateBossMonster(player->getLevel());
		Sleep(1000);
		
		printMessage.bossAppears();
	}

	printMessage.printFrame();
	cout << endl;
	printMessage.printFrame();
	printMessage.textColor(4);
	cout << "       _,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-." << endl;
	
	printMessage.printFrame();
	cout << "                " << monster->getName()
		<< " 발견 (HP:" << monster->getHealth() << ", DAMAGE:" << monster->getAttack() << ")" << endl;
	printMessage.printFrame();
	printMessage.textColor(4);
	cout << "       _,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-." << endl;

	while (!player->isDead() && !monster->isDead())
	{
		// 플레이어가 공격하기 전에 아이템 사용
		player->useRandomItem();

		// 독 물약 먹고 플레이어가 죽을 수도 있음
		if (player->isDead())
		{
			break;
		}

		// 플레이어 -> 몬스터 공격
		printMessage.printFrame();
		cout << "       " << player->getName() << "가(이) " << monster->getName() << "을(를) 공격!  ";
		monster->takeDamage(player->getAttack());

		// 몬스터가 죽으면 경험치와 골드 획득, 가끔 아이템도 드롭 + 전투 종료
		if (monster->isDead()) {
			// 아이템 드롭(몬스터) 및 아이템 획득(플레이어)
			printMessage.printFrame();

			//			cout << "      -------------------------------------------------" << endl;
			printMessage.textColor(6);
			//cout << "      =====================================================" << endl;
			cout << "      ===================="; printMessage.textColor(96); cout << " R E S U L T "; printMessage.textColor(6); cout << "====================" << endl;
			printMessage.textColor(7);

			Item* dropedItem = monster->dropItem();
			if (dropedItem != nullptr)
			{
				player->getDropedItem(dropedItem);
			}

			// 잡은 몬스터가 보스이면
			if (dynamic_cast<BossMonster*>(monster) != nullptr)
			{
				killBoss = true;
			}

			// 일반 몬스터를 잡았을 때만 출력
			if (killBoss == false)
			{
				// 경험치 및 골드 획득
				int gainGold = randomGold();
				printMessage.printFrame();
				cout << "      >> " << player->getName() << "가(이) 30EXP와 " << gainGold << " 골드를 획득" << endl;
				player->addExperience(30, nullptr);
				player->addGold(gainGold);
				printMessage.printFrame();
				cout << endl;

				totalGold += gainGold;
				totalKilledMonster++;
			}

			countKilledMonster(monster->getName());
			delete monster;
			break;
		}

		// 몬스터 -> 플레이어 공격
		printMessage.printFrame();
		cout << "       " << monster->getName() << "가(이) " << player->getName() << "을(를) 공격!  ";
		player->takeDamage(monster->getAttack());

		// 플레이어가 죽으면 전투 종료
		if (player->isDead())
		{
			break;
		}

		printMessage.printFrame();
		cout << "         [" << turnCounter << "] 턴 종료.  <아무 키나 눌러 다음 턴 진행>" << endl;
		_getch();

		turnCounter++;
	}
}

void GameManager::visitShop(Character* player)
{
	PrintMessage printMessage;

	printMessage.printFrame();
	cout << endl;

	string visitShop = "";		// 상점 방문 여부를 입력 받는 string
	string menu = "";			// 상점에 들어가서 뭘 할지 입력 받는 string

	while (1)
	{
		if (menu == "3")
		{
			break;
		}

		printMessage.printFrame();
		cout << "      상점을 방문하시겠습니까? (Y/N) : ";
		getline(cin, visitShop);		// 상점 방문 여부 입력

		if (visitShop == "y" || visitShop == "Y")
		{
			// 방문
			Shop shop;	

			shop.visitShop(player, menu);
		}
		else if (visitShop == "n" || visitShop == "N")
		{
			// 방문하지 않음
			break;
		}
		else
		{
			// 예외 처리
			printMessage.printFrame();
			cout << "      ※ 잘못된 입력입니다 ※" << endl;
		}
	}
}

int GameManager::randomGold()
{
	return generateRandomNumber(10, 20);
}

void GameManager::displayRPGResult()
{
	PrintMessage printMessage;
	char lookResult;


	printMessage.printFrame();
	cout << endl;
	printMessage.printFrame();
	cout << "             게임 결과를 보시겠습니까? (Y/N) : ";
	cin >> lookResult;

	if (lookResult == 'y' || lookResult == 'Y')
	{
		printMessage.printFrame();
		cout << endl;
		printMessage.printFrame(); cout << "       __| |____________________________________________| |__" << endl;
		printMessage.printFrame(); cout << "      (__   ____________________________________________   __)" << endl;
		printMessage.printFrame(); cout << "         | |                모 험 결 산                 | |" << endl;
		printMessage.printFrame(); cout << "         | |                                            | |" << endl;
		printMessage.printFrame(); cout << "         | |   - 슬라임 :             " << totalKilledSlime << "  마리" << string(12 - to_string(totalKilledSlime).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |   - 고블린 :             " << totalKilledGoblin << "  마리" << string(12 - to_string(totalKilledGoblin).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |   - 오크 :               " << totalKilledOrc << "  마리" << string(12 - to_string(totalKilledOrc).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |   - 산적 :               " << totalKilledBandit << "  마리" << string(12 - to_string(totalKilledBandit).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |   - 트롤 :               " << totalKilledTroll << "  마리" << string(12 - to_string(totalKilledTroll).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |   - 악마 :               " << totalKilledBoss << "  마리" << string(12 - to_string(totalKilledBoss).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |                                            | |" << endl;
		printMessage.printFrame(); cout << "         | |  물리친 몬스터 : 총      " << totalKilledMonster << "  마리" << string(12 - to_string(totalKilledMonster).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "         | |  획득 골드량  :  총      " << totalGold << "  골드" << string(12 - to_string(totalGold).length(), ' ') << "| |" << endl;
		printMessage.printFrame(); cout << "       __| |____________________________________________| |__" << endl;
		printMessage.printFrame(); cout << "      (__   ____________________________________________   __)" << endl;
		printMessage.printFrame(); cout << "         | |                                            | |" << endl;
	}
	printMessage.printLowerFrame();

	printMessage.gotoXY(0, 29); // 좌측 맨아래로 커서 이동
	_getch();
}