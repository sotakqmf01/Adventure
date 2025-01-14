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
Troll::Troll(int level) : name("Ʈ��")
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
	// �ǰ� �� ü�� ����
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		cout << "* " << name << " óġ! *" << endl;
	}
	else
	{
		cout << "(" << name << " ü�� : " << health << ")" << endl;
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
			cout << "? ������ ������ ������ ������ϴ�\n\n";
		}
	}
	return item;
}
