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
	BigScroll() : name("대형 공격력 데미지 스크롤"), attackIncrease(30), price(100)
	{
		attackIncrease = 30;
	};
	string getName()
	{
		return "대형 공격력 데미지 스크롤";
	};
	int getPrice()
	{
		return 100;
	};
};