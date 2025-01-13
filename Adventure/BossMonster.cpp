#pragma once
#include "BossMonster.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- Devil ----------------------------
BossMonster::BossMonster(int level) : name("����� �Ǹ�")
{
	difficulty = 1.8;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
}

string BossMonster::getName()
{
	return name;
}

int BossMonster::getHealth() const
{
	return health;
}

int BossMonster::getAttack() const
{
	return attack;
}

float BossMonster::getDifficulty() const
{
	return difficulty;
}

void BossMonster::takeDamage(int damage)
{
	// �ǰ� �� ü�� ����
	health -= damage;
	if (health <= 0) {
		health = 0;
		cout << "* " << name << " óġ! *" << endl;
	}
	else {
		cout << "(" << name << " ü�� : " << health << ")" << endl;
	}
}

bool BossMonster::isDead()
{
	return health <= 0 ? true : false;
}

Item* BossMonster::dropItem()
{
	Item* item = nullptr;
	int dropProbability = generateRandomNumber(1, 100);
	if (dropProbability <= 30) {
		switch (generateRandomNumber(0, 1)) {
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
