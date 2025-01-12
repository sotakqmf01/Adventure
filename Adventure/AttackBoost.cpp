#include "AttackBoost.h"
#include "Character.h"
#include <iostream>
#include "Item.h"

using namespace std;

AttackBoost::AttackBoost() : name("��ũ��"), attackIncrease(0), price(50)
{
};

string AttackBoost::getName()
{
	return name;
};

int HealthPotion::getPrice()
{
	return price;
};

void AttackBoost::use(Character* character)
{
	cout << " �� " << character->getName() << "��(��) " << name << "��(��) ����߽��ϴ�";
	character->enhanceAttack(attackIncrease);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
};

