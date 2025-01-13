#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : name("������"), attackIncrease(10)
{
}

string AttackBoost::getName()
{
	return name;
}

void AttackBoost::use(Character* character)
{
	cout << " �� " << character->getName() << "��(��) " << name << "��(��) ����߽��ϴ�";
	character->enhanceAttack(attackIncrease);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
}