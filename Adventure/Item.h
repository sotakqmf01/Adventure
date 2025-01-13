#pragma once
#include <string>
#include <vector>
#include "ATtackBoost.h"
#include "HealthPotion.h"
#include "Character.h"
using namespace std;

class Item
{
public:
	vector<Item*> items;
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual void use(Character* character) = 0;
	void itemlistSet() {};
	void additem(Item* item) {};
};


