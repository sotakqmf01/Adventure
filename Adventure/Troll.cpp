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
	ItemList* itemlist = new ItemList;

	int index = generateRandomNumber(0, (int)itemlist->items.size() - 1);
	item = itemlist->items[index];

	itemlist->items.erase(itemlist->items.begin() + index);
	delete itemlist;
	return item;
}
