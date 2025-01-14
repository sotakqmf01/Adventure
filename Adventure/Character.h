#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character 
{
private:

	static Character* instance;		// 珥湲고 .cpp 댁＜湲
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int remainingExperience;		// ⑥ 寃쏀移
	int maxExperience;				// 理 寃쏀移
	int experience;
	int gold;
	vector<Item*> inventory;


public:

	static Character* getInstance(const string& name);
	void displayStatus();
	void levelUp();
	void useRandomItem();		
	void enhanceAttack(int attackIncrease);		// 怨듦꺽�μ 뱀ㅺ린  ⑥
	void Heal(int heal);						//  泥대 蹂
	void takeDamage(int damage);				// 怨듦꺽 諛 
	bool isDead();
	void addExperience(int exp);				// 寃쏀移 	
	void addGold(int _gold);					// 怨⑤ 
	void getDropedItem(Item* item);				// 紐ъㅽ 泥移   댄 
	void showInventory();
	vector<Item*>& getInventory();
	void sortInventoryByName();																//댄 ��

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
