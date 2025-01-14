#include <iostream>
#include "HealthPotion.h"
#include "SmallPotion.h"
using namespace std;


SmallPotion::SmallPotion() : name("소형 물약"), price(50), healthRestore(15)
	{
	};
string SmallPotion::getName()
	{
		return "소형 물약";
	};
int SmallPotion:: getPrice()
	{
		return 50;
	};
