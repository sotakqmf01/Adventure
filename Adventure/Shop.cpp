#include "Item.h"
#include "Character.h"
#include <iostream>
#include "GenerateRandomNumber.h"
#include <vector>
#include "Shop.h"

using namespace std;


Shop::Shop() : itemlist(new ItemList())			// 상점에 아이템들을 무작위로 넣음

{
	itemlist->itemlistSet();

	vector<Item*> ShopItems;

	for (int i = 0; i < 4; i++)
	{
		int e = generateRandomNumber(0, (int)itemlist->items.size() - 1);
		ShopItems.push_back(itemlist->items[e]);
	};
};


void Shop::showShop()							// 상점에 진열된 아이템을 출력
{
	for (int i = 0; i < ShopItems.size(); i++)
	{
		cout << i + 1 << "번" << ShopItems[i]->getName() << " 가격은 : " << ShopItems[i]->getPrice() << endl;
	};
};

Item* Shop::buyItem(int index, Character* character)						// 아이템 구매
{
	vector<Item*> inven = character->getInventory();
	Item* item = ShopItems[index];

	if (index < 0 || index >= ShopItems.size())
	{
		cout << "잘못된 번호입니다." << endl;
		return nullptr;
	}
	if (character->getGold() > ShopItems[index]->getPrice())		// 보유한 금액이 포션 값보다 클때
	{
		character->setGold(character->getGold() - ShopItems[index]->getPrice());
		inven.push_back(ShopItems[index]);
		character->setInventory(inven);

		cout << ShopItems[index]->getName() << " 을(를) 구매 하였습니다." << " 보유한 금액 : " << character->getGold() << " 원 입니다." << endl;

		ShopItems.erase(ShopItems.begin() + index);
	}
	return nullptr;
};

void Shop::Reroll()								// 혹시 몰라서 만든건데 상점의 아이템을 삭제하고 다시 아이템을 넣어서 출력
{
	ShopItems.clear();
	for (int i = 0; i < 4; i++)
	{
		int e = generateRandomNumber(0, (int)itemlist->items.size() - 1);
		ShopItems.push_back(itemlist->items[e]);
	};
};


Character* Shop::sellItem(int index, Character* character)				// 아이템을 판매
{
	vector<Item*> inven = character->getInventory();

	if (inven.empty())
	{
		cout << "인벤토리가 비어있습니다." << endl;
		return nullptr;
	}

	if (index < 0 || index >= inven.size()) 
	{
		cout << "잘못된 번호입니다. 판매할 아이템을 다시 선택하세요." << endl;
		return nullptr; 
	}

	if (inven.size() >= 1)
	{
		int gold = inven[index]->getPrice();
		character->addGold(gold);

		cout << inven[index]->getName() << " 을(를) 판매 하였습니다." << " 보유한 금액 : " << character->getGold() << " 원 입니다." << endl;

		inven.erase(inven.begin() + index);
	}
	character->setInventory(inven);

	return character;
};

Shop::~Shop()
{
	delete itemlist;
}
