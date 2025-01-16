#include "HealthPotion.h"
#include "Character.h"
#include "printMessage.h"
#include <iostream>
#include "Item.h"

using namespace std;

HealthPotion::HealthPotion(string name, int price, int healthRestore)
	: name(name), price(price), healthRestore(healthRestore)
{
}

string HealthPotion::getName()
{
	return name;
}

int HealthPotion::getPrice()
{
	return price;
}

void HealthPotion::use(Character* character)
{
	PrintMessage printMessage;
	
	printMessage.printFrame();
	cout << "       �� " << character->getName() << "��(��) "; printMessage.textColor(13); cout << name; printMessage.textColor(7); cout << "��(��) ����߽��ϴ�";
	
	character->Heal(healthRestore);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
}

