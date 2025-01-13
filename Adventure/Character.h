#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;		// 珥湲??.cpp? ?댁＜湲?
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
	void useRandomItem();		// inventory??? index踰?吏?????ъ
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	// ? 以??쇨꺽
	bool isDead();					// 罹由?곌? ?щ??
	void addExperience(int exp);	// ? ?밸━ ??寃쏀移??
	void addGold(int _gold);		// ? ?밸━ ??怨⑤ ?/?� 援щℓ/?� ?留
	void getDropedItem(Item* item);
	void showInventory();
	const vector<Item*>& getInventory();
	void setInventory(const vector<Item*>& newInventory);

	// get/set ? ? 諛⑸???? ?쇰 留?대낫怨????⑥濡?留??嫄??媛?대낫??
	// 紐ъ?곗 泥대, 怨듦꺽?μ ?踰???
	// ?대 ??????泥由щ??ш린???대由щ㈃ ??takeDamage, addExperience ??
	int getLevel() { return level; }
	string& getName() { return name; }

	// ???怨듦꺽???????
	int getGold() { return gold; }
	int setGold(int golds) { return gold; }
	// 전투에 공격력 알아야 함
	int getAttack() { return attack; }
};