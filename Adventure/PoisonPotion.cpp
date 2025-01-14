#include <iostream>
#include "HealthPotion.h"
#include "PoisonPotion.h"
using namespace std;


PoisonPotion::PoisonPotion() : name("독 물약"), price(-150), healthRestore(15)
	{
		healthRestore = -30;
	};
string PoisonPotion:: getName()
	{
		return "독 물약";
	};
int PoisonPotion :: getPrice()
	{
		return -150;
	};
