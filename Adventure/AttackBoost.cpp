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

	character->enhanceAttack(attackIncrease);

	
	delete this;
}