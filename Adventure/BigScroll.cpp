#include <iostream>
#include "AttackBoost.h"
#include "BigScroll.h"
using namespace std;

BigScroll::BigScroll() : name("���� ���ݷ� ������ ��ũ��"), attackIncrease(30), price(100)
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