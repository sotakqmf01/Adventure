#include <iostream>
#include "HealthPotion.h"
#include "SmallPotion.h"
using namespace std;


SmallPotion::SmallPotion() : name("���� ����"), price(50), healthRestore(15)
	{
	};
string SmallPotion::getName()
	{
		return "���� ����";
	};
int SmallPotion:: getPrice()
	{
		return 50;
	};
