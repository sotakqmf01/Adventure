﻿#include "Item.h"
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
#include "printMessage.h"
using namespace std;

Shop::Shop()
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
		cout << "상점에 아이템이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < shopItems.size(); i++)
		{
			string name = shopItems[i]->getName();

			printMessage.printFrame();
			cout << i + 1 << "번  " << name << string(28 - name.length(), ' ') << "Gold : " << shopItems[i]->getPrice() << endl;
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
		// 어짜피 showShop에서 상점에 아이템이 없다는 것을 보여줌
		// => shopItems.empty()일 때 아무것도 하지않고 넘어가면 됨
		//printMessage.printFrame();
		//cout << "---- 구매할 수 있는 아이템이 없습니다." << endl;
	}
	else
	{
		vector<Item*>& inven = character->getInventory();
		Item* item = shopItems[index-1];

		if (index <= 0 || index > shopItems.size())
		{
			printMessage.printFrame();
			cout << "---- 잘못된 번호입니다." << endl;
		}
		else
		{
			string name = item->getName();
			if (character->getGold() > item->getPrice())		// 보유한 금액이 포션 값보다 클때
			{
				character->setGold(character->getGold() - item->getPrice());
				inven.push_back(item);

				printMessage.printFrame();
				cout << "---- " << item->getName() << "을(를) 구매 완료" << string(40 - (name.length()+10), ' ') 
					<< " (보유 골드 : " << character->getGold() << ")" << endl;

				shopItems.erase(shopItems.begin() + index - 1);
			}
			else
			{
				printMessage.printFrame();
				cout << "---- " << "금액 부족, [필요 골드] : " << item->getPrice() << string(35 - 17, ' ')
					<< "  (보유 골드 : " << character->getGold() << ")" << endl;
			}
		}
	}	
}

void Shop::Reroll()
{
	shopItems.clear();
	makeShopList();
}

void Shop::sellItem(int index, Character* character)				
{
	vector<Item*>& inven = character->getInventory();
	PrintMessage printMessage;

	if (inven.empty())
	{
		printMessage.printFrame();
		cout << "---- 판매할 수 있는 아이템이 없습니다." << endl;	
	}
	else if (index <= 0 || index > inven.size()) 
	{
		printMessage.printFrame();
		cout << "---- 잘못된 번호입니다." << endl;
	}
	else
	{
		Item* item = inven[index - 1];
		string name = item->getName();
		int gold = item->getPrice();

		character->addGold(gold);

		printMessage.printFrame();
		cout << "---- " << item->getName() << "을(를) 판매 완료" << string(40 - (name.length() + 10), ' ')
			<< " (보유 골드 : " << character->getGold() << ")" << endl;
		
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
