#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character 
{
private:

	static Character* instance;
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int remainingExperience;
	int maxExperience;
	int experience;
	int gold;
	vector<Item*> inventory;


public:

	static Character* getInstance(const string& name);
	void displayStatus();
	void levelUp();
	void useRandomItem();		
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);
	bool isDead();
	void addExperience(int exp);
	void addGold(int _gold);
	void getDropedItem(Item* item);
	void showInventory();
	vector<Item*>& getInventory();
	void sortInventoryByName();
	// get/set 없이 하는 방법이 있나? 일단 만들어보고 다 함수로 만드는 거 생각해보자
	// 몬스터의 체력, 공격력에 레벨이 필요
	// 어떤 행동에 대한 처리를 여기서 해버리면 됨(takeDamage, addExperience 등)

	int getLevel() { return level; }
	string& getName() { return name; }

	int getGold() { return gold; }
	void setGold(int golds) { gold = golds; }
	// 전투에 공격력 알아야 함
	int getAttack() { return attack; }
};
