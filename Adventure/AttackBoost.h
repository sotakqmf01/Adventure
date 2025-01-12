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

// ��ũ�� ����Ʈ

class SmallScroll : public AttackBoost
{
public:
	SmallScroll()
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

class SmallDebuffScroll : public AttackBoost
{
public:
	SmallDebuffScroll()
	{
		attackIncrease = -15;
	};
	string getName()
	{
		return "���� ���ݷ� ����� ��ũ��";
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
		return "���� ���ݷ� ������ ��ũ��";
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
		return "���� ���ݷ� ����� ��ũ��";
	};
	int getPrice()
	{
		return 100;
	};
};

