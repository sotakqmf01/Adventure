#include <iostream>
#include "GenerateRandomNumber.h"
#include <vector>
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Shop.h"
#include "BigPotion.h"
#include "MiddlePotion.h"
#include "SmallPotion.h"
#include "LagePotion.h"
#include "SmallScroll.h"
#include "BigScroll.h"
#include "BigExperienceBook.h"
#include "SmallExperienceBook.h"
//#include "BigPoisonPotion.h"
#include "printMessage.h"
#include <stdexcept>		// 예외 처리를 위한 헤더
using namespace std;

Shop::Shop() : rerollCount(1)	// 리롤 1회
{
	// 상점에 아이템들을 무작위로 4개 넣음
	makeShopList();
}

// 상점에 진열된 아이템을 출력
void Shop::showShop()
{
	PrintMessage printMessage;

	if (shopItems.empty())
	{
		printMessage.printFrame();
		cout << "      상점에 아이템이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < shopItems.size(); i++)
		{
			string name = shopItems[i]->getName();

			printMessage.printFrame();
			cout << "      " << i + 1 << "번  " << name << string(28 - name.length(), ' ') << "Gold : " << shopItems[i]->getPrice() << endl;
		}
	}
	printMessage.printFrame();
	cout << endl;
}

void Shop::buyItem(int index, Character* character)
{
	PrintMessage printMessage;

	if (shopItems.empty())
	{
		// 어차피 showShop에서 상점에 아이템이 없다는 것을 보여줌
		// => shopItems.empty()일 때 아무것도 하지않고 넘어가면 됨
		//printMessage.printFrame();
		//cout << "---- 구매할 수 있는 아이템이 없습니다." << endl;
	}
	else
	{
		vector<Item*>& inven = character->getInventory();

		if (index <= 0 || index > shopItems.size())
		{
			printMessage.printFrame();
			cout << "      ※ 잘못된 번호입니다 ※" << endl;
		}
		else
		{
			Item* item = shopItems[index - 1];
			string itemName = item->getName();
			int itemPrice = item->getPrice();
			itemPrice = itemPrice < 0 ? -itemPrice : itemPrice;

			if(inven.size() >= 20)
			{
				printMessage.printFrame();
				cout << "      ---- 인벤토리가 가득 차 아이템을 구매하실 수 없습니다." << endl;
			}
			else if (character->getGold() >= itemPrice)		// 보유한 금액이 포션 값보다 클때
			{
				character->setGold(character->getGold() - itemPrice);
				inven.push_back(item);

				printMessage.printFrame();
				cout << "      ---- " << item->getName() << "을(를) 구매 완료" << string(34 - (itemName.length()+10), ' ')
					<< "    [보유 골드 : " << character->getGold() << "]" << endl;

				shopItems.erase(shopItems.begin() + index - 1);
			}
			else
			{
				printMessage.printFrame();
				cout << "      ---- 골드 부족, [필요 골드] : " << itemPrice << string(28 - 17, ' ')
					<< "     [보유 골드 : " << character->getGold() << "]" << endl;
			}
		}
	}	
}

void Shop::Reroll()
{
	if (rerollCount > 0)
	{
		shopItems.clear();
		makeShopList();

		rerollCount--;
	}
	else
	{
		PrintMessage printMessage;

		printMessage.printFrame();
		cout << "                ☆ 리롤 횟수가 없습니다 ☆" << endl;
	}
}

void Shop::sellItem(int index, Character* character)				
{
	vector<Item*>& inven = character->getInventory();
	PrintMessage printMessage;

	if (inven.empty())
	{
		printMessage.printFrame();
		cout << "      ---- 판매할 수 있는 아이템이 없습니다." << endl;	
	}
	else if (index <= 0 || index > inven.size()) 
	{
		printMessage.printFrame();
		cout << "      ※ 잘못된 번호입니다 ※" << endl;
	}
	else
	{
		Item* item = inven[index - 1];
		string itemName = item->getName();
		int itemGold = item->getPrice();

		if (itemGold > 0)
		{
			itemGold *= 0.6f;
		}

		if (character->getGold() + itemGold <= 0)
		{
			printMessage.printFrame();
			cout << "      ---- 아이템을 판매하실 수 없습니다.(골드 부족)" << string(3 , ' ')
				<< "[보유 골드 : " << character->getGold() << "]" << endl;
		}
		else
		{
			character->setGold(character->getGold() + itemGold);

			printMessage.printFrame();
			cout << "      ---- " << item->getName() << "을(를) 판매 완료" << string(34 - (itemName.length() + 10), ' ')
				<< "    [보유 골드 : " << character->getGold() << "]" << endl;

			inven.erase(inven.begin() + index - 1);

			delete item;
		}
	}
}

void Shop::makeShopList()
{
	Item* item;
	for (int i = 0; i < 4; i++)
	{
		int randomNumber = generateRandomNumber(1, 8);
		switch (randomNumber)
		{
		case 1:
			item = new SmallPotion;
			break;
		case 2:
			item = new MiddlePotion;
			break;
		case 3:
			item = new LagePotion;
			break;
		case 4:
			item = new BigPotion;
			break;
		case 5:
			item = new SmallScroll;
			break;
		case 6:
			item = new BigScroll;
			break;
		case 7:
			item = new BigExperienceBook;
			break;
		case 8:
			item = new SmallExperienceBook;
			break;
		default:
			break;
		}
		shopItems.push_back(item);
	}
}

void Shop::visitShop(Character* player, string& menu)
{
	PrintMessage printMessage;
	string itemSelect = "";		// 구매하거나 판매할 아이템 번호를 입력받는 string

	while (menu != "3")
	{
		// 구매창이나 판매창에서 뒤로가기(0)해서 메뉴로 나오면
		// itemSelect가 0이라서 메뉴에서 구매(1), 판매(2)를 눌러도 while문을 바로 빠져나옴
		// => 초기화 해줄 필요가 있음
		itemSelect = "";
		printMessage.printShopRoof();

		printMessage.printFrame();
		cout << "      ▶ 1.아이템 구매   2.아이템 판매   3.나가기" << endl;
		printMessage.printFrame();
		cout << "      ▶ 선택 : ";
		getline(cin, menu);			// 상점에서 뭘 할 것인지 입력

		if (menu == "1")
		{
			// 구매
			while (itemSelect != "0")
			{
				printMessage.printShopRoof();

				printMessage.printFrame();
				cout << "                     - 판 매 목 록 -" << endl;
				showShop();

				printMessage.printFrame();
				cout << "      ▶ 아이템 번호 입력 시 구매(리롤:5, 뒤로가기:0)   [보유 골드 : " << player->getGold() << "]" << endl;
				printMessage.printFrame();
				cout << "      ▶ 선택 (리롤 " << getRerollCount() << "회) : ";
				getline(cin, itemSelect);		// 구매할 아이템 번호 입력

				if (itemSelect == "5")
				{
					// 리롤
					Reroll();
				}
				else if (itemSelect == "0")
				{
					// 뒤로가기(메뉴 선택 창으로 돌아가기)
					break;
				}
				else
				{
					int itemIndex = 0;

					// 구매 시 예외 처리
					try {
						itemIndex = stoi(itemSelect);
					}
					catch (const invalid_argument& e) {
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}
					catch (const out_of_range&) {
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}

					if (to_string(itemIndex) != itemSelect)
					{
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}

					buyItem(itemIndex, player);
				}
			}
		}
		else if (menu == "2")
		{
			// 판매
			while (itemSelect != "0")
			{
				printMessage.printShopRoof();

				player->showInventory();

				printMessage.printFrame();
				cout << "      ▶ 아이템 번호 입력 시 판매(뒤로가기:0) : ";
				getline(cin, itemSelect);		// 판매할 아이템 번호 입력

				if (itemSelect == "0")
				{
					// 뒤로가기(메뉴 선택 창으로 돌아가기)
					break;
				}
				else
				{
					int itemIndex = 0;

					try {
						itemIndex = stoi(itemSelect);
					}
					catch (const invalid_argument& e) {
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}
					catch (const out_of_range& e) {
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}

					if (to_string(itemIndex) != itemSelect)
					{
						printMessage.printFrame();
						cout << "      ※ 잘못된 입력입니다 ※" << endl;
						continue;
					}

					sellItem(itemIndex, player);
				}
			}
		}
		else if (menu == "3")
		{
			// 나가기
			break;
		}
		else
		{
			// 예외 처리
			printMessage.printFrame();
			cout << "      ※ 잘못된 번호입니다 ※" << endl;
		}
	}
}

Shop::~Shop()
{
	for (Item* item : shopItems)
	{
		delete item;
	}
}
