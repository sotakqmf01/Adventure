#pragma once
#include <string>
using namespace std;

class Item;

class Monster {
public:
	virtual string getName() = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;
	virtual float getDifficulty() const = 0;
	virtual bool isDead() = 0;
	virtual Item* dropItem() = 0;

};
