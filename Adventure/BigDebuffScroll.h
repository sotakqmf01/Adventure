#pragma once
#include <iostream>
#include "AttackBoost.h"
using namespace std;

class BigDebuffScroll	: public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;

public:
	BigDebuffScroll();
	string getName() override;
	int getPrice() override;
};

