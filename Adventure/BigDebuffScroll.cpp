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
	BigDebuffScroll() : name("대형 공격력 디버프 스크롤"), attackIncrease(0), price(-200)
	{
		attackIncrease = -30;
	};
	string getName()
	{
		return "대형 공격력 디버프 스크롤";
	};
	int getPrice()
	{
		return -200;
	};
};
