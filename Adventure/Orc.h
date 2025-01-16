#pragma once
#include "Monster.h"

class Orc : public Monster
{
private:
	string name;
	int health;
	int attack;
	float difficulty;

public:
	Orc(int level);
	string getName() override;
	int getHealth() const override;
	int getAttack() const override;
	void takeDamage(int damage) override;
	float getDifficulty() const override;
	bool isDead() override;
	Item* dropItem() override;
};