#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

HealthPotion::HealthPotion() : name("힐 포션"), healthRestore(50)
{
}

string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	cout << " ☆ " << character->getName() << "가(이) " << name << "을(를) 사용했습니다";
	character->Heal(healthRestore);

	// 아이템이 사용되고 나면 객체 메모리 해제
	delete this;
}
