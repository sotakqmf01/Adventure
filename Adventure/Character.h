#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;		// 초기화 .cpp에서 해주기
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
	void useRandomItem();		// inventory에 있는 index번 째 아이템 사용
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	// 전투 중 피격
	bool isDead();					// 캐릭터가 사망했나?
	void addExperience(int exp);	// 전투 승리 시 경험치 획득
	void addGold(int _gold);		// 전투 승리 시 골드 획득/상점 구매/상점 판매
	void getDropedItem(Item* item);
	void showInventory();

	// get/set 없이 하는 방법이 있나? 일단 만들어보고 다 함수로 만드는 거 생각해보자
	// 몬스터의 체력, 공격력에 레벨이 필요
	// 어떤 행동에 대한 처리를 여기서 해버리면 됨(takeDamage, addExperience 등)
	int getLevel() { return level; }
	string& getName() { return name; }

	// 전투에 공격력 알아야 함
	int getAttack() { return attack; }
};