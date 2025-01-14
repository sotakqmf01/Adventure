#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>

using namespace std;

class Shop
{
private:
	vector<Item*> shopItems;
public:
	Shop();
	~Shop();
	void showShop();	// 상점 보여주기	
	void buyItem(int index, Character* character);	// 아이템 구매	
	void Reroll();		// 상점 리롤
	void sellItem(int index, Character* character); // 아이템 판매	
	void makeShopList(); //shopItems 4개의 값 넗기

};

