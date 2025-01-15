#pragma once
#include "Goblin.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "printMessage.h"
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
	PrintMessage printMessage;
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
	ItemList* itemlist = new ItemList;

	int index = generateRandomNumber(0, (int)itemlist->items.size() - 1);
	item = itemlist->items[index];

	itemlist->items.erase(itemlist->items.begin() + index);
	delete itemlist;
	return item;
}
