#include <iostream>
#include "AttackBoost.h"
using namespace std;

class SmallDebuffScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	SmallDebuffScroll() : name("���� ���ݷ� ����� ��ũ��"), attackIncrease(-15), price(-100)
	{
		attackIncrease = -15;
	};
	string getName()
	{
		return "���� ���ݷ� ����� ��ũ��";
	};
	int getPrice()
	{
		return -100;
	};
};