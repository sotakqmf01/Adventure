#include <iostream>
#include "AttackBoost.h"
#include "SmallDebuffScroll.h"
using namespace std;


SmallDebuffScroll::SmallDebuffScroll() : name("���� ���ݷ� ����� ��ũ��"), attackIncrease(-15), price(-100)
	{
		attackIncrease = -15;
	};
string SmallDebuffScroll:: getName()
	{
		return "���� ���ݷ� ����� ��ũ��";
	};
int SmallDebuffScroll:: getPrice()
	{
		return -100;
	};