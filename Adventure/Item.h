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
	virtual ~Item() {}
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual void use(Character* character) = 0;
};

class ItemList
{private:
	vector<Item*> items;
public :
	void itemlistSet() {};
	void additem(Item* item) {};
};
 

