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
	
	printMessage.printFrame();
	cout << "       �� " << character->getName() << "��(��) " << name << "��(��) ����߽��ϴ�";
	
	character->addExperience(experiencePoints, this);

	// �������� ���ǰ� ���� ��ü �޸� ����
	delete this;
}

