#include <iostream>
#include "AttackBoost.h"
#include "BigDebuffScroll.h"
using namespace std;

BigDebuffScroll::BigDebuffScroll() : name("���� ���ݷ� ����� ��ũ��"), attackIncrease(0), price(-200)
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