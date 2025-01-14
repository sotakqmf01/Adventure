#include "ExperienceBoost.h"
#include "Character.h"
#include "printMessage.h"
#include <iostream>
#include "Item.h"
using namespace std;

ExperienceBoost::ExperienceBoost(string name, int price, int experiencePoints)
	: name(name), price(price), experiencePoints(experiencePoints)
{

}

string ExperienceBoost::getName()
{
	return name;
}

int ExperienceBoost::getPrice()
{
	return price;
}

void ExperienceBoost::use(Character* character)
{
	PrintMessage printMessage;
	printMessage.textColor(6);
	cout << "          |       |                                                                                     |       |";
	printMessage.textColor(7);
	printMessage.gotoXY(26, printMessage.getcursorlocationY());
	cout << " �� " << character->getName() << "��(��) " << name << "��(��) ����߽��ϴ�";
	character->addExperience(experiencePoints);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
}

