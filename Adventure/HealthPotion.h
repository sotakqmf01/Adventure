#pragma once
#include <iostream>
#include "Item.h"
#include "Character.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

class HealthPotion : public Item
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	HealthPotion();
	string getName();
	int getPrice();
	void use(Character* character);
};

/// ���� ����Ʈ
class SmallPotion : public HealthPotion
{
public:
	SmallPotion()
	{
		healthRestore = 15;
	};
	string getName()
	{
		return "���� ����";
	};
	int getPrice()
	{
		return 50;
	};
};

class MiddlePotion : public HealthPotion
{
public:
	MiddlePotion()
	{
		healthRestore = 30;
	};
	string getName()
	{
		return "���� ����";
	};
	int getPrice()
	{
		return 75;
	};
};

class LagePotion : public HealthPotion
{
public:
	LagePotion()
	{
		healthRestore = 50;
	};
	string getName()
	{
		return "���� ����";
	};
	int getPrice()
	{
		return 100;
	};
};

class PoisonPotion : public HealthPotion
{
public:
	PoisonPotion()
	{
		healthRestore = -30;
	};
	string getName()
	{
		return "�� ����";
	};
	int getPrice()
	{
		return 50;
	};
};

class BigPotion : public HealthPotion
{
public:
	BigPotion()
	{
		healthRestore = 100;
	};
	string getName()
	{
		return "�ʴ��� ����";
	};
	int getPrice()
	{
		return 150;
	};
};

