#include <iostream>
#include "AttackBoost.h"
#include "SmallScroll.h"
using namespace std;


SmallScroll::SmallScroll() : name("���� ���ݷ� ������ ��ũ��"), attackIncrease(15), price(50)
{
	attackIncrease = 15;
}

string SmallScroll:: getName()
{
	return name;
}

int SmallScroll:: getPrice()
{
	return price;
}