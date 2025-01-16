#include "Item.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include "BigPotion.h"
#include "MiddlePotion.h"
#include "SmallPotion.h"
#include "LagePotion.h"
#include "SmallPoisonPotion.h"
#include "BigPoisonPotion.h"
#include "SmallScroll.h"
#include "BigScroll.h"
#include "BigDebuffScroll.h"
#include "SmallDebuffScroll.h"
#include "BigExperienceBook.h"
#include "SmallExperienceBook.h"
using namespace std;

ItemList::ItemList() 
{
	// 물약
	items.push_back(new SmallPotion);
	items.push_back(new MiddlePotion);
	items.push_back(new LagePotion);
	items.push_back(new SmallPoisonPotion);
	items.push_back(new BigPoisonPotion);
	items.push_back(new BigPotion);
	// 스크롤
	items.push_back(new SmallScroll);
	items.push_back(new SmallDebuffScroll);
	items.push_back(new BigScroll);
	items.push_back(new BigDebuffScroll);
	// 경험치 책
	items.push_back(new BigExperienceBook);
	items.push_back(new SmallExperienceBook);
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

