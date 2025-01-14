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
	printMessage.askName();
	//cout << "============================================" << endl;
	//cout << "            환영합니다. 모험가님!\n";
	//cout << "============================================" << endl;
	//cout << " 캐릭터명을 입력하세요 : ";
	getline(cin, name);			// 이름이 공백이면 다시 입력하도록하는 부분 나중에 추가?
	cout << endl;
	/*system("cls");*/
	Character* player = Character::getInstance(name);
	printMessage.afterName(name);
	
	//cout << "        ** 캐릭터 [" << name << "] 생성 완료! **" << endl;
	//player->displayStatus();
	
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
		system("cls");
		
		printMessage.bossAppears();
	}

	printMessage.printFrame();
	cout << endl;
	printMessage.printFrame();
	cout << "      *************************************************" << endl;
	printMessage.printFrame();
	cout << "                " << monster->getName()
		<< " 발견 (HP:" << monster->getHealth() << ", DAMAGE:" << monster->getAttack() << ")" << endl;
	printMessage.printFrame();;
	cout << "      *************************************************" << endl;

	while (!player->isDead() && !monster->isDead())
	{
		

		// 플레이어가 공격하기 전에 아이템 사용
		player->useRandomItem();

		// 플레이어 -> 몬스터 공격
		printMessage.printFrame();
		cout << "       " << player->getName() << "가(이) " << monster->getName() << "을(를) 공격!  ";
		monster->takeDamage(player->getAttack());

		// 몬스터가 죽으면 경험치와 골드 획득, 가끔 아이템도 드롭 + 전투 종료
		if (monster->isDead()) {
			// 아이템 드롭(몬스터) 및 아이템 획득(플레이어)
			printMessage.printFrame();
			cout << "      -------------------------------------------------" << endl;
			Item* dropedItem = monster->dropItem();
			if (dropedItem != nullptr)
			{
				player->getDropedItem(dropedItem);
			}

			// 경험치 및 골드 획득
			int gainGold = randomGold();
			printMessage.printFrame();
			cout << "      >> " << player->getName() << "가(이) 30EXP와 " << gainGold << " 골드를 획득" << endl;
			player->addExperience(30);
			player->addGold(gainGold);

			totalGold += gainGold;
			totalKilledMonster++;

			if (dynamic_cast<BossMonster*>(monster) != nullptr)
			{
				killBoss = true;
			}

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
		cout << "      " << turnCounter << " 턴 종료. 아무 키나 눌러 다음 턴 진행." << endl;
		_getch();

		turnCounter++;
	}
}

void GameManager::visitShop(Character* player)
{
	PrintMessage printMessage;

	printMessage.printFrame();
	char visitShop;
	cout << "      상점을 방문하시겠습니까? (Y/N) : ";
	cin >> visitShop;
	if (visitShop == 'y' || visitShop == 'Y')
	{
		Shop shop;
		char menu = 0;
		int	itemSelect = 1;

		while (menu != '3')
		{
			printMessage.printShopRoof();

			printMessage.printFrame();
			cout << "       1.아이템 구매   2.아이템 판매   3.나가기" << endl;
			printMessage.cursorView(0);
			menu = _getch();
			printMessage.cursorView(1);

			switch (menu)
			{
			case '1':
				itemSelect = 1;
				while (itemSelect != 0)
				{
					printMessage.printShopRoof();

					printMessage.printFrame();
					cout << "                     - 판 매 목 록 -" << endl;
					shop.showShop();

					printMessage.printFrame();
					cout << "      ▶ 구매 아이템 선택(리롤:5, 뒤로가기:0) : ";
					cin >> itemSelect;

					// cin으로 입력을 받을 때 타입이 다르면 입력 실패 상태가 됨
					// => 입력 실패 상태가 되면 해당 변수는 원래 가지고 있는 값을 그대로 가짐
					// => 입력 실패 상태가 되면 새로운 입력을 받기 전에 스트림의 상태를 정리해야 함
					if (cin.fail()) {
						cin.clear();
						cin.ignore(INT_MAX, '\n');  // 입력 버퍼 비우기
						itemSelect = 0;
					}

					if (itemSelect == 5)
					{
						shop.Reroll();
					}
					else if (itemSelect == 0)
					{
						break;
					}
					else
					{
						shop.buyItem(itemSelect, player);
					}
				}
				break;
			case '2':
				itemSelect = 1;
				while (itemSelect != 0)
				{
					printMessage.printShopRoof();

					player->showInventory();

					printMessage.printFrame();
					cout << "      ▶ 판매 아이템 선택(뒤로가기:0) : ";
					cin >> itemSelect;

					if (cin.fail()) {
						cin.clear();
						itemSelect = 0;
					}

					if (itemSelect == 0)
					{
						break;
					}
					else
					{
						shop.sellItem(itemSelect, player);
					}
				}
				break;
			case '3':
				break;
			default:
				printMessage.printFrame();
				cout << "      ※ 잘못된 번호입니다 ※" << endl;
				break;
			}
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
	cout << "      게임 결과를 보시겠습니까? (Y/N) : ";
	printMessage.printFrame();
	cin >> lookResult;

	if (lookResult == 'y' || lookResult == 'Y')
	{
		//system("cls");
		printMessage.printFrame();
		cout << "      =============게임 결과=============" << endl;
		printMessage.printFrame();;
		cout << "      > 몬스터 처치 수 : " << totalKilledMonster << endl;
		printMessage.printFrame();
		cout << "      > 획득 골드량 : " << totalGold << endl;
		printMessage.printFrame();
		cout << "      ==================================" << endl;
		printMessage.printLowerFrame();
	}
}