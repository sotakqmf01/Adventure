#pragma once
#include "Orc.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

extern random_device rd;

// --------------------- ORC ----------------------------
Orc::Orc(int level) : name("��ũ")
{
	health = level * generateRandomNumber(50, 60);
	attack = level * generateRandomNumber(3, 8);
}

string Orc::getName() const
{
	return name;
}

int Orc::getHealth() const
{
	return health;
}

int Orc::getAttack() const
{
	return attack;
}

void Orc::takeDamage(int damage)
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

bool Orc::isDead()
{
	return health <= 0 ? true : false;
}

Item* Orc::dropItem()
{
	Item* item = nullptr;
	ItemList* itemlist = nullptr;
	itemlist->itemlistSet();

	int index = generateRandomNumber(0, (int)itemlist->items.size());
	item = itemlist->items[index];

	return item;
}
