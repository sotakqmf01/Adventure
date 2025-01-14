#pragma once
#include <iostream>
#include "HealthPotion.h"
using namespace std;

class SmallPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;

public:
	SmallPotion();
	string getName() override;
	int getPrice() override;
};