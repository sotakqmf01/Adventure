#pragma once
#include "Item.h"
#include "Character.h"
#include <iostream>
using namespace std;

class ExperienceBoost : public Item
{
protected:
	string name;
	int experiencePoints;
	int price;
public:
	ExperienceBoost(string name, int price, int experiencePoints);
	string getName()override;
	int getPrice()override;
	void use(Character* character)override;
};

