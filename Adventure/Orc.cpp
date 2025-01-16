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
// ��ũ�� ������ ��� �κ��� �ٸ�
Orc::Orc(int level)
{
	vector<string> orcNames = { "ũ����", "�Ʊ׽�", "�߷ν�", "���ڱ�", "�ٵ��", "��ũ��", "��ũ��", "����", "ī�̸�", "�߶���", "�ڵ��"};
	int vectorsize = orcNames.size()-1;
	difficulty = 1.1;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "��ũ " + orcNames[generateRandomNumber(0,vectorsize)];
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