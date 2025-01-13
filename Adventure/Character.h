#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;		// 초기??.cpp?�서 ?�주�?
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<Item*> inventory;

private:
	Character(const string& name);

public:
	static Character* getInstance(const string& name);
	void displayStatus();
	void levelUp();
	void useRandomItem();		// inventory???�는 index�?�??�이???�용
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	// ?�투 �??�격
	bool isDead();					// 캐릭?��? ?�망?�나?
	void addExperience(int exp);	// ?�투 ?�리 ??경험�??�득
	void addGold(int _gold);		// ?�투 ?�리 ??골드 ?�득/?�점 구매/?�점 ?�매
	void getDropedItem(Item* item);
	void showInventory();

	// get/set ?�이 ?�는 방법???�나? ?�단 만들?�보�????�수�?만드??�??�각?�보??
	// 몬스?�의 체력, 공격?�에 ?�벨???�요
	// ?�떤 ?�동???�??처리�??�기???�버리면 ??takeDamage, addExperience ??
	int getLevel() { return level; }
	string& getName() { return name; }

	// ?�투??공격???�아????
	int getAttack() { return attack; }
};