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
	cout << "       ☆ " << character->getName() << "가(이) "; printMessage.textColor(13); cout << name; printMessage.textColor(7); cout << "을(를) 사용했습니다";
	
	character->Heal(healthRestore);

	// 아이템이 사용되고 나면 객체 메모리 해제
	delete this;
}

