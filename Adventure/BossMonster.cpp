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
BossMonster::BossMonster(int level) : name("고대의 악마")
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
	// 피격 시 체력 감소
	health -= damage;
	if (health <= 0) {
		health = 0;
		cout << "* " << name << " 처치! *" << endl;
	}
	else {
		cout << "(" << name << " 체력 : " << health << ")" << endl;
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
			cout << "? 아이템 생성에 문제가 생겼습니다\n\n";
		}
	}
	return item;
}
