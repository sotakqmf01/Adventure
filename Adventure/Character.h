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
	void enhanceAttack(int attackIncrease);
	void Heal(int heal);
	void takeDamage(int damage);	
	bool isDead();					
	void addExperience(int exp);	
	void addGold(int _gold);		
	void getDropedItem(Item* item);
	void showInventory();
	vector<Item*>& getInventory();
	void setInventory(const vector<Item*>& newInventory);

	// get/set ���� �ϴ� ����� �ֳ�? �ϴ� ������ �� �Լ��� ����� �� �����غ���
	// ������ ü��, ���ݷ¿� ������ �ʿ�
	// � �ൿ�� ���� ó���� ���⼭ �ع����� ��(takeDamage, addExperience ��)
	int getLevel() { return level; }
	string& getName() { return name; }

	
	int getGold() { return gold; }
	int setGold(int golds) { return gold; }
	// ������ ���ݷ� �˾ƾ� ��
	int getAttack() { return attack; }
};