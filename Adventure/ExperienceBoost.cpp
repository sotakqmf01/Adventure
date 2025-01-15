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
	cout << "       ☆ " << character->getName() << "가(이) " << name << "을(를) 사용했습니다";
	
	character->addExperience(experiencePoints, this);

	// 아이템이 사용되고 나면 객체 메모리 해제
	delete this;
}

