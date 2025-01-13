#pragma once
#include "Monster.h"
#include <string>
#include <vector>

class Bandit : public Monster
{
private:
	vector<string> banditNames;
	string name;
	int health;
	int attack;
	float difficulty;

public:
	Bandit(int level);
	string getName() override;
	int getHealth() const override;
	int getAttack() const override;
	void takeDamage(int damage) override;
	float getDifficulty() const override;
	bool isDead() override;
	Item* dropItem() override;
};