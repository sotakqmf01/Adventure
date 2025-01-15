#pragma once
#include "BossMonster.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "printMessage.h"
using namespace std;

// --------------------- Devil ----------------------------
BossMonster::BossMonster(int level) : name("고대의 악마")
{
	difficulty = 2.0;
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
	PrintMessage printMessage;
	int prevHealth = health;

	// 피격 시 체력 감소
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		cout << "* " << name << " 처치! *" << endl;
		printMessage.printFrame();
		cout << endl;
	}
	else
	{
		cout << "(" << name << " 체력 : " << prevHealth << " → " << health << ")" << endl;
	}
}

bool BossMonster::isDead()
{
	return health <= 0 ? true : false;
}

Item* BossMonster::dropItem()
{
	return nullptr;
}
