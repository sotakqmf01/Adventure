#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	static Character* instance;		// �ʱ�ȭ .cpp���� ���ֱ�
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
	void useRandomItem();		
	void enhanceAttack(int attackIncrease);		// ���ݷ��� ��½�Ű�� ���� �Լ�
	void Heal(int heal);						// ���� ü�� ȸ��
	void takeDamage(int damage);				// ������ �޾��� ��
	bool isDead();
	void addExperience(int exp);				// ����ġ ȹ��	
	void addGold(int _gold);					// ��� ȹ��
	void getDropedItem(Item* item);				// ���� óġ �� ����� ������ ȹ��
	void showInventory();
	vector<Item*>& getInventory();

	// get/set ���� �ϴ� ����� �ֳ�? �ϴ� ������ �� �Լ��� ����� �� �����غ���
	// ������ ü��, ���ݷ¿� ������ �ʿ�
	// � �ൿ�� ���� ó���� ���⼭ �ع����� ��(takeDamage, addExperience ��)
	int getLevel() { return level; }
	string& getName() { return name; }

	int getGold() { return gold; }
	void setGold(int golds) { gold = golds; }
	// ������ ���ݷ� �˾ƾ� ��
	int getAttack() { return attack; }
};