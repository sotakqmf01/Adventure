#include "HealthPotion.h"
#include "Character.h"
#include "printMessage.h"
#include <iostream>
#include "Item.h"
using namespace std;

HealthPotion::HealthPotion() : name("물약"), price(50), healthRestore(0)
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
	cout << " ☆ " << character->getName() << "가(이) " << name << "을(를) 사용했습니다";
	character->Heal(healthRestore);

	// 아이템이 사용되고 나면 객체 메모리 해제
	delete this;
};

