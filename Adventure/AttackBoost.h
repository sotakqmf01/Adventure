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
	AttackBoost();
	string getName();
	int getPrice();
	void use(Character* character);
};

