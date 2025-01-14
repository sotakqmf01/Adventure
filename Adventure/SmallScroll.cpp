#include <iostream>
#include "AttackBoost.h"
#include "SmallScroll.h"
using namespace std;


SmallScroll::SmallScroll() : name("소형 공격력 데미지 스크롤"), attackIncrease(15), price(50)
	{
		attackIncrease = 15;
	};
string SmallScroll:: getName()
	{
		return "소형 공격력 데미지 스크롤";
	};
int SmallScroll:: getPrice()
	{
		return 50;
	};