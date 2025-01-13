#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>

using namespace std;

class Shop
{
private:
	vector<Item*> ShopItems;
	ItemList* itemlist;
	vector<Item*> inven;

public:
	Shop();
	~Shop();
	void showShop();				// 상점 보여주기	
	Item* buyItem(int index, Character* character);	// 아이템 구매	
	void Reroll();					// 상점 리롤
	Character* sellItem(int index, Character* character); // 아이템 판매
};

