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
