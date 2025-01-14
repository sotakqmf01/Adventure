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
	SmallDebuffScroll() : name("소형 공격력 디버프 스크롤"), attackIncrease(-15), price(-100)
	{
		attackIncrease = -15;
	};
	string getName()
	{
		return "소형 공격력 디버프 스크롤";
	};
	int getPrice()
	{
		return -100;
	};
};