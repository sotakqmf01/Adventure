#include <iostream>
#include "AttackBoost.h"
#include "SmallDebuffScroll.h"
using namespace std;


SmallDebuffScroll::SmallDebuffScroll() : name("소형 공격력 디버프 스크롤"), attackIncrease(-15), price(-100)
	{
		attackIncrease = -15;
	};
string SmallDebuffScroll:: getName()
	{
		return "소형 공격력 디버프 스크롤";
	};
int SmallDebuffScroll:: getPrice()
	{
		return -100;
	};