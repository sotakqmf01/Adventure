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
	HealthPotion(string name, int price, int healthRestore);
	string getName() override;
	int getPrice() override;
	void use(Character* character) override;
};
