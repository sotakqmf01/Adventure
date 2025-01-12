#pragma once
#include "Slime.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- SLIME ----------------------------
Slime::Slime(int level) : name("������")
{
	difficulty = 0.5;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	
}

string Slime::getName()
{
	return name;
}

int Slime::getHealth() const
{
	return health;
}

int Slime::getAttack() const
{
	return attack;
}
float Slime::getDifficulty() const
{
	return difficulty;
}
void Slime::takeDamage(int damage)
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

bool Slime::isDead()
{
	return health <= 0 ? true : false;
}

Item* Slime::dropItem()
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
