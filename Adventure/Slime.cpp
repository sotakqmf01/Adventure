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
// �������� ������ ��� �κ��� �ٸ�
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
	PrintMessage printMessage;
	int prevHealth = health;

	// �ǰ� �� ü�� ����
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		cout << "* " << name << " óġ! *" << endl;
		printMessage.printFrame();
		cout << endl;
	}
	else
	{
		cout << "(" << name << " ü�� : " << prevHealth << " �� " << health << ")" << endl;
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