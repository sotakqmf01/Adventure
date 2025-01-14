#include <iostream>
#include "HealthPotion.h"
#include "PoisonPotion.h"
using namespace std;


PoisonPotion::PoisonPotion() : name("µ¶ ¹°¾à"), price(-150), healthRestore(15)
{
	healthRestore = -30;
}

string PoisonPotion:: getName()
{
	return name;
}

int PoisonPotion :: getPrice()
{
	return price;
}

