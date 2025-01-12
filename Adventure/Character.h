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
	void useRandomItem();		// inventory�� �ִ� index�� ° ������ ���
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	// ���� �� �ǰ�
	bool isDead();					// ĳ���Ͱ� ����߳�?
	void addExperience(int exp);	// ���� �¸� �� ����ġ ȹ��
	void addGold(int _gold);		// ���� �¸� �� ��� ȹ��/���� ����/���� �Ǹ�
	void getDropedItem(Item* item);
	void showInventory();

	// get/set ���� �ϴ� ����� �ֳ�? �ϴ� ������ �� �Լ��� ����� �� �����غ���
	// ������ ü��, ���ݷ¿� ������ �ʿ�
	// � �ൿ�� ���� ó���� ���⼭ �ع����� ��(takeDamage, addExperience ��)
	int getLevel() { return level; }
	string& getName() { return name; }

	// ������ ���ݷ� �˾ƾ� ��
	int getAttack() { return attack; }
};