#include "Item.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
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

ItemList::ItemList() 
{
	items.push_back(new SmallPotion);
	items.push_back(new MiddlePotion);
	items.push_back(new LagePotion);
	items.push_back(new PoisonPotion);
	items.push_back(new BigPotion);
	// 위에는 포션 아래는 스크롤
	items.push_back(new SmallScroll);
	items.push_back(new SmallDebuffScroll);
	items.push_back(new BigScroll);
	items.push_back(new BigDebuffScroll);
}


void ItemList::additem(Item* item)
{
	items.push_back(item);
};

ItemList::~ItemList()
{
	for (Item* item : items) 
	{
		delete item;
	}	
	items.clear();
};

