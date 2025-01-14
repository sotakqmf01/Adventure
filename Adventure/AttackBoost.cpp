#include "AttackBoost.h"
#include "Character.h"
#include <iostream>
#include "Item.h"
using namespace std;

AttackBoost::AttackBoost() : name ("스크롤"), attackIncrease(0), price(50)
{
}

string AttackBoost::getName()
{
	return name;
}

int AttackBoost::getPrice()
{
	return price;
}

void AttackBoost::use(Character* character)
{
	cout << " ☆ " << character->getName() << "가(이) " << name << "을(를) 사용했습니다";
	character->enhanceAttack(attackIncrease);
	// 아이템이 사용되고 나면 객체 메모리 해제
	delete this;
}