#include <iostream>
#include "AttackBoost.h"
#include "BigScroll.h"
using namespace std;

class BigScroll : public AttackBoost
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	BigScroll() : name("���� ���ݷ� ������ ��ũ��"), attackIncrease(30), price(100)
	{
		attackIncrease = 30;
	};
	string getName()
	{
		return "���� ���ݷ� ������ ��ũ��";
	};
	int getPrice()
	{
		return 100;
	};
};