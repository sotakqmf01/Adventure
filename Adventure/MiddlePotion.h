#pragma once
#include <iostream>
#include "HealthPotion.h"
using namespace std;

class MiddlePotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;

public:
	MiddlePotion();
	string getName();
	int getPrice();
};