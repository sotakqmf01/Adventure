#include <iostream>
#include "HealthPotion.h"
#include "BigPotion.h"
using namespace std;

BigPotion::BigPotion() : name("초대형 물약"), price(150), healthRestore(100)
{
	healthRestore = 100;
}

string BigPotion::getName()
{
	return name;
}

int BigPotion:: getPrice()
{
	return price;
}