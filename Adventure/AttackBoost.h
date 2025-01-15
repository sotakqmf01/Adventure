#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>
using namespace std;

class AttackBoost : public Item
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	AttackBoost(string name, int price, int attackIncrease);
	string getName() override;
	int getPrice() override;
	void use(Character* character) override;
};

