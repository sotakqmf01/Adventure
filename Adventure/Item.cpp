#include "Item.h"
#include "Character.h"
#include <iostream>

using namespace std;



ItemList::ItemList()
{
	items.push_back(new SmallPotion);
	items.push_back(new MiddlePotion);
	items.push_back(new LagePotion);
	items.push_back(new PoisonPotion);
	items.push_back(new BigPotion);
	// 위칸은 포션 아이템
	items.push_back(new SmallScroll);
	items.push_back(new SmallDebuffScroll);
	items.push_back(new BigScroll);
	items.push_back(new BigDebuffScroll);
};
ItemList::~ItemList()
{
		for (auto item : items) delete item;
		items.clear();
};
void ItemList ::additem(Item* item)
{
		items.push_back(item);
};

