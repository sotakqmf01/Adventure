#include <iostream>
#include "HealthPotion.h"
#include "MiddlePotion.h"
using namespace std;


MiddlePotion::MiddlePotion() : name("중형 물약"), price(75), healthRestore(30)
	{
		healthRestore = 30;
	};
string MiddlePotion:: getName()
	{
		return "중형 물약";
	};
int MiddlePotion:: getPrice()
	{
		return 75;
	};
