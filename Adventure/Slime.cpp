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
Slime::Slime(int level) : name("슬라임")
{
	health = level * generateRandomNumber(50, 60);
	attack = level * generateRandomNumber(3, 8);
}

string Slime::getName() const
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

void Slime::takeDamage(int damage)
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

bool Slime::isDead()
{
	return health <= 0 ? true : false;
}

Item* Slime::dropItem()
{
	Item* item = nullptr;
	ItemList* itemlist = nullptr;
	itemlist->itemlistSet();

	int index = generateRandomNumber(0, (int)itemlist->items.size());
	item = itemlist->items[index];

	return item;
}
