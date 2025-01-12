#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;
public:
	HealthPotion();
	string getName() override;
	void use(Character* character) override;
};

