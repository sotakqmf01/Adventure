#include <iostream>
#include "HealthPotion.h"
#include "MiddlePotion.h"
using namespace std;

MiddlePotion::MiddlePotion() : name("���� ����"), price(75), healthRestore(30)
{
	healthRestore = 30;
}

string MiddlePotion:: getName()
{
	return name;
}

int MiddlePotion:: getPrice()
{
	return price;
}