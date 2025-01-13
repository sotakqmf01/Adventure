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
	vector<Item*>inven;

public:
	Shop();
	~Shop();
	void showShop();				// ���� �����ֱ�	
	Item* buyItem(int index, Character* character);	// ������ ����	
	void Reroll();					// ���� ����
	Character* sellItem(int index, Character* character); // ������ �Ǹ�
};
