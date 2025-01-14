#include <iostream>
#include "AttackBoost.h"
#include "BigDebuffScroll.h"
using namespace std;

BigDebuffScroll::BigDebuffScroll() : name("대형 공격력 디버프 스크롤"), attackIncrease(0), price(-200)
{
	attackIncrease = -30;
}

string BigDebuffScroll:: getName()
{
	return name;
}

int BigDebuffScroll:: getPrice()
{
	return price;
}