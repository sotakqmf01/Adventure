#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>
using namespace std;

class HealthPotion : public Item
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	HealthPotion();
	string getName();
	int getPrice();
	void use(Character* character);
};
