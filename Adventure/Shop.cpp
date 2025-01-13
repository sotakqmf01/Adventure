#include "Item.h"
#include "Character.h"
#include <iostream>
#include "GenerateRandomNumber.h"
#include <vector>
#include "Shop.h"


using namespace std;


Shop::Shop()
{
	item->itemlistSet();

	vector<Item*> ShopItems;

	for (int i = 0; i < 5; i++)
	{
		int e = generateRandomNumber(0, (int)item->items.size());
		ShopItems.push_back(item->items[e]);
	};

};
Shop::~Shop() {};

void Shop::showShop()
{
	for (int i = 0; i < ShopItems.size(); i++)
	{
		cout << ShopItems[i]->getName() << endl;
	};
};

Item* Shop::buyItem(int index)
{

	Item* item = ShopItems[index];
	ShopItems.erase(ShopItems.begin() + index);
	return item;
};

void Shop::Reroll()
{
	ShopItems.clear();
	for (int i = 0; i < 5; i++)
	{
		int e = generateRandomNumber(0, (int)item->items.size());
		ShopItems.push_back(item->items[e]);
	};
};

Character* Shop:: sellItem(int index) 
{
	
	Character* inventory;


};
