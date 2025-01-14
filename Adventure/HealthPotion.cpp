#include "HealthPotion.h"
#include "Character.h"
#include "printMessage.h"
#include <iostream>
#include "Item.h"
using namespace std;

HealthPotion::HealthPotion() : name("����"), price(50), healthRestore(0)
{
};

string HealthPotion::getName()
{
	return name;
};

int HealthPotion::getPrice()
{
	return price;
};

void HealthPotion::use(Character* character)
{
	PrintMessage printMessage;
	printMessage.textColor(6);
	cout << "          |       |                                                                                     |       |";
	printMessage.textColor(7);
	printMessage.gotoXY(26, printMessage.getcursorlocationY());
	cout << " �� " << character->getName() << "��(��) " << name << "��(��) ����߽��ϴ�";
	character->Heal(healthRestore);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
};

