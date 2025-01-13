#pragma once
#include "Goblin.h"
#include <time.h>
#include <iostream>
#include "GenerateRandomNumber.h"
#include "Item.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
using namespace std;

// --------------------- Goblin ----------------------------
Goblin::Goblin(int level)
{
	vector<string> goblinNames = { "������", "����ũ", "��ũ��Ʈ", "�����ڸ�", "�����ڸ�", "����ε�", "�ɸ���", "��������", "���ɸ�", "��ī��Ʈ", "���ٳ�Ʈ" };
	int vectorsize = goblinNames.size() - 1;
	difficulty = 0.8;
	health = level * getDifficulty() * generateRandomNumber(50, 60);
	attack = level * getDifficulty() * generateRandomNumber(5, 10);
	name = "��� " + goblinNames[generateRandomNumber(0, vectorsize)];

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

bool Goblin::isDead()
{
	return health <= 0 ? true : false;
}

Item* Goblin::dropItem()
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
