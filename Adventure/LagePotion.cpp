#include <iostream>
#include "HealthPotion.h"
#include "LagePotion.h"
using namespace std;

LagePotion::LagePotion() : name("대형 물약"), price(100), healthRestore(50)
{
}

string LagePotion::getName()
{
	return name;
}

int LagePotion::getPrice()
{
	return price;
}