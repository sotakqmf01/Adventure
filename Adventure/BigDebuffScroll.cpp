#include <iostream>
#include "AttackBoost.h"
#include "BigDebuffScroll.h"
using namespace std;

class BigDebuffScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	BigDebuffScroll() : name("���� ���ݷ� ����� ��ũ��"), attackIncrease(0), price(-200)
	{
		attackIncrease = -30;
	};
	string getName()
	{
		return "���� ���ݷ� ����� ��ũ��";
	};
	int getPrice()
	{
		return -200;
	};
};
