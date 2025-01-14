#pragma once
#include <iostream>
#include "AttackBoost.h"
using namespace std;

class SmallScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	SmallScroll();
	string getName();
	int getPrice();
};