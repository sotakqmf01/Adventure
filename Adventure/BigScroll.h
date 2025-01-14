#pragma once
#include <iostream>
#include "AttackBoost.h"
using namespace std;

class BigScroll
	: public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	BigScroll();
	string getName();
	int getPrice();
};