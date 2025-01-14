#pragma once
#include "Troll.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- Troll ----------------------------
Troll::Troll(int level) : name("트롤")
{
	difficulty = 1.4;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
}

string Troll::getName()
{
	return name;
}

int Troll::getHealth() const
{
	return health;
}

int Troll::getAttack() const
{
	return attack;
}

float Troll::getDifficulty() const
{
	return difficulty;
}

void Troll::takeDamage(int damage)
{
	// 피격 시 체력 감소
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		cout << "* " << name << " 처치! *" << endl;
	}
	else
	{
		cout << "(" << name << " 체력 : " << health << ")" << endl;
	}
}

bool Troll::isDead()
{
	return health <= 0 ? true : false;
}

Item* Troll::dropItem()
{
	Item* item = nullptr;
	int dropProbability = generateRandomNumber(1, 100);
	if (dropProbability <= 30)
	{
		switch (generateRandomNumber(0, 1))
		{
		case 0:
			item = new HealthPotion();
			break;
		case 1:
			item = new AttackBoost();
			break;
		default:
			cout << "? 아이템 생성에 문제가 생겼습니다\n\n";
		}
	}
	return item;
}
