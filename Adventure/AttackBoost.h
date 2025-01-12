#pragma once
#include "Item.h"
#include "Character.h"
using namespace std;

class AttackBoost : public Item
{
protected:
	string name;
	int attackIncrease;
	int price;
public:
	AttackBoost() {};
	string getName() {};
	int getPrice() {};
	void use(Character* character) {};
};

// 스크롤 리스트

class SmallScroll : public AttackBoost
{
public:
	SmallScroll()
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

class SmallDebuffScroll : public AttackBoost
{
public:
	SmallDebuffScroll()
	{
		attackIncrease = -15;
	};
	string getName()
	{
		return "대형 공격력 디버프 스크롤";
	};
	int getPrice()
	{
		return 50;
	};
};

class BigScroll : public AttackBoost
{
public:
	BigScroll()
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

class BigDebuffScroll : public AttackBoost
{
public:
	BigDebuffScroll()
	{
		attackIncrease = -30;
	};
	string getName()
	{
		return "대형 공격력 디버프 스크롤";
	};
	int getPrice()
	{
		return 100;
	};
};

