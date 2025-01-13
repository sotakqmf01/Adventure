#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;		// ì´ˆê¸°??.cpp?ì„œ ?´ì£¼ê¸?
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
	void useRandomItem();		// inventory???ˆëŠ” indexë²?ì§??„ì´???¬ìš©
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	// ?„íˆ¬ ì¤??¼ê²©
	bool isDead();					// ìºë¦­?°ê? ?¬ë§?ˆë‚˜?
	void addExperience(int exp);	// ?„íˆ¬ ?¹ë¦¬ ??ê²½í—˜ì¹??ë“
	void addGold(int _gold);		// ?„íˆ¬ ?¹ë¦¬ ??ê³¨ë“œ ?ë“/?ì  êµ¬ë§¤/?ì  ?ë§¤
	void getDropedItem(Item* item);
	void showInventory();

	// get/set ?†ì´ ?˜ëŠ” ë°©ë²•???ˆë‚˜? ?¼ë‹¨ ë§Œë“¤?´ë³´ê³????¨ìˆ˜ë¡?ë§Œë“œ??ê±??ê°?´ë³´??
	// ëª¬ìŠ¤?°ì˜ ì²´ë ¥, ê³µê²©?¥ì— ?ˆë²¨???„ìš”
	// ?´ë–¤ ?‰ë™???€??ì²˜ë¦¬ë¥??¬ê¸°???´ë²„ë¦¬ë©´ ??takeDamage, addExperience ??
	int getLevel() { return level; }
	string& getName() { return name; }

	// ?„íˆ¬??ê³µê²©???Œì•„????
	int getAttack() { return attack; }
};