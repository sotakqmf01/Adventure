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
	Item* item;
	

public:
	Shop() {};
	~Shop() {};	
	void showShop() {};		// ���� �����ֱ�	
	Item* buyItem(int index) {};		// ������ ����	
	void Reroll() {};		// ���� ����
	Character* sellItem(int index) {}; // ������ �Ǹ�
};