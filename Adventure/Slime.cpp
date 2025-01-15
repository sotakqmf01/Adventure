#pragma once
#include "Slime.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "printMessage.h"
using namespace std;

// --------------------- SLIME ----------------------------
// 슬라임은 아이템 드롭 부분이 다름
Slime::Slime(int level) : name("슬라임")
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

bool Slime::isDead()
{
	return health <= 0 ? true : false;
}

Item* Slime::dropItem()
{
	Item* item = nullptr;
	ItemList* itemlist = new ItemList;

	int index = generateRandomNumber(0, (int)itemlist->items.size() - 1);
	item = itemlist->items[index];

	itemlist->items.erase(itemlist->items.begin() + index);
	delete itemlist;
	return item;
}