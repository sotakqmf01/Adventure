#include <iostream>
#include "AttackBoost.h"
using namespace std;

class SmallScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	SmallScroll() : name("���� ���ݷ� ������ ��ũ��"), attackIncrease(15), price(50)
	{
		attackIncrease = 15;
	};
	string getName()
	{
		return "���� ���ݷ� ������ ��ũ��";
	};
	int getPrice()
	{
		return 50;
	};
};