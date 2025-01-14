#pragma once
#include <iostream>
#include "HealthPotion.h"
using namespace std;

class PoisonPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;

public:
	PoisonPotion();
	string getName() override;
	int getPrice() override;
};