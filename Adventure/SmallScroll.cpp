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
	SmallScroll() : name("소형 공격력 데미지 스크롤"), attackIncrease(15), price(50)
	{
		attackIncrease = 15;
	};
	string getName()
	{
		return "소형 공격력 데미지 스크롤";
	};
	int getPrice()
	{
		return 50;
	};
};