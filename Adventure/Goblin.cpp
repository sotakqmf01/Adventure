#pragma once
#include "Goblin.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- Goblin ----------------------------
Goblin::Goblin(int level)
{
	vector<string> goblinNames = { "나스고르", "고르로크", "마크기트", "나스코르", "가르코르", "아흐로드", "케르륵", "께륵께륵", "케케륵", "무카기트", "가바나트" };
	int vectorsize = goblinNames.size() - 1;
	difficulty = 0.8;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "고블린 " + goblinNames[generateRandomNumber(0, vectorsize)];

}

string Goblin::getName()
{
	return name;
}

int Goblin::getHealth() const
{
	return health;
}

int Goblin::getAttack() const
{
	return attack;
}

float Goblin::getDifficulty() const
{
	return difficulty;
}

void Goblin::takeDamage(int damage)
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

bool Goblin::isDead()
{
	return health <= 0 ? true : false;
}

Item* Goblin::dropItem()
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
