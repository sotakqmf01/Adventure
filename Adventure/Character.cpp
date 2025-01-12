#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"
using namespace std;
//test dev123
Character::Character(const string& name)
	: name(name), level(1), health(100), maxHealth(100), attack(15), experience(0), gold(0)
{

}

Character* Character::getInstance(const string& name)
{
	if (instance == nullptr)
		instance = new Character(name);
	return instance;
}

void Character::displayStatus()
{
	cout << "        ---------- stat ----------" << endl;
	cout << "        name :       " << name << endl;
	cout << "        level :      " << level << endl;
	cout << "        health :     " << health << "/" << maxHealth << endl;
	cout << "        attack :     " << attack << endl;
	cout << "        experience : " << experience << "/100" << endl;
	cout << "        gold :       " << gold << endl;
	cout << "        --------------------------" << endl << endl << endl;
}

void Character::levelUp()
{
	if (level < 10) {
		level++;
		maxHealth = maxHealth + (level * 20);
		attack = attack + (level * 5);
		health = maxHealth;
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "           LEVEL UP�� ü�¡� ���ݷ¡� " << endl;
		cout << "  �ִ� ü�� : " << maxHealth - (level * 20) << " -> " << maxHealth
			<< ", ���ݷ� : " << attack - (level * 5) << " -> " << attack << endl;
		cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	}
}

void Character::useRandomItem()
{
	// �������� ������ ���� ���
	if (inventory.size() >= 1) {
		int maxIndex = (int)inventory.size() - 1;
		int index = generateRandomNumber(0, maxIndex);

		inventory[index]->use(instance);
		// ����ϰ��� ���Ϳ��� ����
		inventory.erase(inventory.begin() + index);
	}
}

void Character::enhanceAttack(int attackIncrease)
{
	attack += attackIncrease;
	cout << " (" << attack - attackIncrease << " -> " << attack << ")" << endl;
}

void Character::Heal(int heal)
{
	health += heal;
	if (health > maxHealth)
		health = maxHealth;
	cout << " (" << health - heal << " -> " << health << ")" << endl;
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0) {
		health = 0;
		cout << "(" << name << " ü�� : " << health << ")" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << ">> �Ф� " << name << "��(��) ����߽��ϴ�. GAME OVER" << endl;
	}
	else {
		cout << "(" << name << " ü�� : " << health << ")" << endl;
	}
}

bool Character::isDead()
{
	return health <= 0 ? true : false;
}

void Character::addExperience(int exp)
{
	if (level < 10) {
		experience += exp;
		if (experience >= 100) {
			levelUp();
			experience -= 100;
		}
	}
}

void Character::addGold(int _gold)
{
	gold += _gold;
}

void Character::getDropedItem(Item* item)
{
	inventory.push_back(item);
	cout << ">> " << name << "��(��) [�� " << item->getName() << "]��(��) ������ϴ�!" << endl;
}

Character* Character::instance = nullptr;
