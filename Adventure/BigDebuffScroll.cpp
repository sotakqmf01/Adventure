#include <iostream>
#include "AttackBoost.h"
#include "BigDebuffScroll.h"
using namespace std;

BigDebuffScroll::BigDebuffScroll() : name("���� ���ݷ� ����� ��ũ��"), attackIncrease(-30), price(-200)
{
}

string BigDebuffScroll:: getName()
{
	return name;
}

int BigDebuffScroll:: getPrice()
{
	return price;
}