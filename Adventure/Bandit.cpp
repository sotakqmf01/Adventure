#pragma once
#include "Bandit.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include "printMessage.h"
using namespace std;

// --------------------- Bandit ----------------------------
Bandit::Bandit(int level)
{
	vector<string> banditNames = { "������", "����", "��", "�", "����", "�ڽ�", "�ٸ�Ʈ", "�κ�", "Į", "����", "�轼" };
	int vectorsize = banditNames.size() - 1;
	difficulty = 1.0;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "���� " + banditNames[generateRandomNumber(0, vectorsize)];
}

string Bandit::getName()
{
	return name;
}

int Bandit::getHealth() const
{
	return health;
}

int Bandit::getAttack() const
{
	return attack;
}

float Bandit::getDifficulty() const
{
	return difficulty;
}

void Bandit::takeDamage(int damage)
{
	PrintMessage printMessage;

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
		cout << "(" << name << " ü�� : " << health << ")" << endl;
	}
}

bool Bandit::isDead()
{
	return health <= 0 ? true : false;
}

Item* Bandit::dropItem()
{
	Item* item = nullptr;
	ItemList* itemlist = new ItemList;

	int index = generateRandomNumber(0, (int)itemlist->items.size() - 1);
	item = itemlist->items[index];

	itemlist->items.erase(itemlist->items.begin() + index);
	delete itemlist;
	return item;
}
