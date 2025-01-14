#pragma once
#include "Bandit.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- Bandit ----------------------------
Bandit::Bandit(int level)
{
	vector<string> banditNames = { "보리스", "존스", "잭", "헨리", "미켈", "핸슨", "바르트", "로벤", "칼", "빌리", "잭슨" };
	int vectorsize = banditNames.size() - 1;
	difficulty = 1.0;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "산적 " + banditNames[generateRandomNumber(0, vectorsize)];
}

string Bandit::getName()
{
	return name;
}

int Bandit::getHealth() const
{
	return health;
}

int Bandit::getAttack() const
{
	return attack;
}

float Bandit::getDifficulty() const
{
	return difficulty;
}

void Bandit::takeDamage(int damage)
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

bool Bandit::isDead()
{
	return health <= 0 ? true : false;
}

Item* Bandit::dropItem()
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
