#include <iostream>
#include "AttackBoost.h"
#include "BigScroll.h"
using namespace std;

BigScroll::BigScroll() : name("대형 공격력 데미지 스크롤"), attackIncrease(30), price(100)
{
}

string BigScroll:: getName()
{
	return name;
}

int BigScroll:: getPrice()
{
	return price;
}