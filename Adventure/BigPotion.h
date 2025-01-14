#pragma once
#include <iostream>
#include "HealthPotion.h"
using namespace std;

class BigPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	BigPotion();
	string getName();
	int getPrice();
};