#pragma once
#include "Item.h"
using namespace std;

class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;
public:
	AttackBoost();
	string getName() override;
	void use(Character* character) override;
};

