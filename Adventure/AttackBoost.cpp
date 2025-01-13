癤#include "AttackBoost.h"
#include "Character.h"
#include <iostream>
#include "Item.h"

using namespace std;


AttackBoost::AttackBoost() : name("스크롤"), attackIncrease(0), price(50)

{
};

string AttackBoost::getName()
{
	return name;
};

int AttackBoost::getPrice()
{
	return price;
};

void AttackBoost::use(Character* character)
{
	cout << "  " << character->getName() << "媛() " << name << "(瑜) ъ⑺듬";
	character->enhanceAttack(attackIncrease);

	// 댄 ъ⑸怨 硫 媛泥 硫紐⑤━ 댁
	delete this;
};
