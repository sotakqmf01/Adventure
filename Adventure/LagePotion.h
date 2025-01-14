#pragma once
#include <iostream>
#include "HealthPotion.h"
using namespace std;

class LagePotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;

public:
	LagePotion();
	string getName();
	int getPrice();
};