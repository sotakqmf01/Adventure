#pragma once
#include <iostream>
#include "AttackBoost.h"
using namespace std;

class SmallDebuffScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;

public:
	SmallDebuffScroll();
	string getName() override;
	int getPrice() override;
};

