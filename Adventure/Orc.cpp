#pragma once
#include "Orc.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "printMessage.h"
using namespace std;

// --------------------- ORC ----------------------------
// 오크는 아이템 드롭 부분이 다름
Orc::Orc(int level)
{
	vector<string> orcNames = { "크라취", "아그쉬", "발로쉬", "아자그", "바드룩", "고크묵", "나크둠", "고르막", "카이막", "발라취", "코드룩"};
	int vectorsize = orcNames.size()-1;
	difficulty = 1.1;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "오크 " + orcNames[generateRandomNumber(0,vectorsize)];
}

string Orc::getName()
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

float Orc::getDifficulty() const
{
	return difficulty;
}

void Orc::takeDamage(int damage)
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

bool Orc::isDead()
{
	return health <= 0 ? true : false;
}

Item* Orc::dropItem()
{
	Item* item = nullptr;
	ItemList* itemlist = new ItemList;

	int index = generateRandomNumber(0, (int)itemlist->items.size() - 1);
	item = itemlist->items[index];

	itemlist->items.erase(itemlist->items.begin() + index);
	delete itemlist;
	return item;
}