#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character 
{
private:
	static Character* instance;			// 초기화 .cpp에서 해주기
	string name;
	int level;
	int health;  
	int maxHealth;
	int attack;
	int remainingExperience;			// 남은 경험치
	int maxExperience;					// 최대 경험치
	int experience;
	int gold;
	vector<Item*> inventory;

private:
	Character(const string& name);

public:
	static Character* getInstance(const string& name);
	void displayStatus();
	void levelUp();
	void useRandomItem();		
	void enhanceAttack(int attackIncrease);		// 공격력을 상승시키기 위한 함수
	void Heal(int heal);						// 현재 체력 회복
	void takeDamage(int damage);				// 공격을 받았을 때
	bool isDead();
	void addExperience(int exp);				// 경험치 획득
	void addGold(int _gold);					// 골드 획득
	void getDropedItem(Item* item);				// 몬스터 처치 후 드랍된 아이템 획득
	void showInventory();
	vector<Item*>& getInventory();
	void sortInventoryByName();					//아이템 정렬

	int getLevel() { return level; }
	string getName() { return name; }

	int getGold() { return gold; }
	void setGold(int golds) { gold = golds; }
	
	int getAttack() { return attack; }
};
