#include "Item.h"
#include "Character.h"
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
#include "PoisonPotion.h"
#include "SmallScroll.h"
#include "BigScroll.h"
#include "BigDebuffScroll.h"
#include "SmallDebuffScroll.h"
using namespace std;

Shop::Shop()			// 상점에 아이템들을 무작위로 넣음
{
	makeShopList();
}

void Shop::showShop()							// 상점에 진열된 아이템을 출력
{
	for (int i = 0; i < shopItems.size(); i++)
	{
		if (shopItems.empty())
		{
			cout << "아이템 없음" << endl;
		}
		else
		{
			cout << i + 1 << "번         " << shopItems[i]->getName() << "     금액은 : " << shopItems[i]->getPrice() << " 원" << endl;
		}
	}
}

void Shop::buyItem(int index, Character* character)						// 아이템 구매
{
	if (shopItems.empty())
	{
		cout << "구매할 수 있는 아이템 없음" << endl;
	}
	else
	{
		vector<Item*>& inven = character->getInventory();
		Item* item = shopItems[index-1];

		if (index <= 0 || index > shopItems.size())
		{
			cout << "잘못된 번호입니다." << endl;
	
		}
		else
		{
			if (character->getGold() > item->getPrice())		// 보유한 금액이 포션 값보다 클때
			{
				character->setGold(character->getGold() - item->getPrice());
				inven.push_back(item);

				cout << item->getName() << " 을(를) 구매 하였습니다." << " 보유한 금액 : " << character->getGold() << " 원 입니다." << endl;

				shopItems.erase(shopItems.begin() + index - 1);
			}
			else
			{
				cout << item->getName() << " 을(를) 구매 할 수 없습니다." << " 보유한 금액 : " << character->getGold() << " 원 입니다." << endl;
			}
		}
	}	
}

void Shop::Reroll()								// 혹시 몰라서 만든건데 상점의 아이템을 삭제하고 다시 아이템을 넣어서 출력
{
	shopItems.clear();
	makeShopList();
}

void Shop::sellItem(int index, Character* character)				// 아이템을 판매
{
	vector<Item*>& inven = character->getInventory();
	
	if (inven.empty())
	{
		cout << "     판매할 수 있는 아이템이 없습니다." << endl;	
	}
	else if (index <= 0 || index > inven.size()) 
	{
		cout << "잘못된 번호입니다." << endl;
	}
	else
	{
		Item* item = inven[index - 1];
		int gold = item->getPrice();
		character->addGold(gold);
		cout << "         " << item->getName() << " 을(를) 판매 하였습니다." << " 보유한 금액 : " << character->getGold() << " 원 입니다." << endl;
		inven.erase(inven.begin() + index-1);
		delete item;
	}
}

void Shop::makeShopList()
{
	Item* item;
	for (int i = 0; i < 4; i++)
	{
		int randomNumber = generateRandomNumber(1, 6);
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
		default:
			break;
		}
		shopItems.push_back(item);
	}
}

Shop::~Shop()
{
	for (Item* item : shopItems)
	{
		delete item;
	}
}
