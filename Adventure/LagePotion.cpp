#include <iostream>
#include "HealthPotion.h"
#include "LagePotion.h"
using namespace std;

LagePotion::LagePotion() : name("���� ����"), price(100), healthRestore(50)
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