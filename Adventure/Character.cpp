#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"
#include "Shop.h"
using namespace std;

Character::Character(const string& name)
	: name(name), level(1), health(200), maxHealth(2000), attack(300), experience(0), gold(0)
{
	cout << name << " 생성 :" << " 레벨, " << level << "체력: " << health << "경험치: " << experience << "골드: " << gold << endl;
}

Character* Character::getInstance(const string& name)
{
	if (instance == nullptr) 
	{
		instance = new Character(name);
	}
	return instance;
}

void Character::displayStatus()
{
	cout << "        ---------- stat ----------" << endl;
	cout << "        name		: " << name << endl;
	cout << "        level		: " << level << endl;
	cout << "        health		: " << health << "/" << maxHealth << endl;
	cout << "        attack		: " << attack << endl;
	cout << "        experience : " << experience << "/100" << endl;
	cout << "        gold :       " << gold << endl;
	showInventory();
	cout << "        --------------------------" << endl << endl << endl;

}

void Character::levelUp()
{
	if (level < 10) {
		level++;
		maxHealth = maxHealth + (level * 13);
		attack = attack + (level * 2);
		health = maxHealth;
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "           LEVEL UP↑ 체력↑ 공격력↑ " << endl;
		cout << "  최대 체력 : " << maxHealth - (level * 20) << " -> " << maxHealth
			<< ", 공격력 : " << attack - (level * 5) << " -> " << attack << endl;
		cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	}
}

void Character::useRandomItem()
{
	// 아이템이 있으면 랜덤 사용
	if (inventory.size() >= 1)
	{
		// 30%로아이템 사용
		if (generateRandomNumber(0, 30))
		{
			int maxIndex = (int)inventory.size() - 1;
			int index = generateRandomNumber(0, maxIndex);

			inventory[index]->use(instance);
			// 사용하고나면 벡터에서 삭제
			inventory.erase(inventory.begin() + index);
		}
	}
}

void Character::showInventory()
{

	if (inventory.size() < 1)
	{
		cout << "        인벤토리가 비어 있습니다." << endl;
	}
	else
	{
		for (size_t i = 0; i < inventory.size(); ++i)
		{
			cout << "        " << i + 1 << ". " << inventory[i]->getName() << endl;
		}
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
	if ( health > maxHealth )
		health = maxHealth;
	cout << " (" << health - heal << " -> " << health << ")" << endl;
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if ( health <= 0 )
	{
		health = 0;
		cout << "(" << name << " 체력 : " << health << ")" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << ">> ㅠㅠ " << name << "가(이) 사망했습니다. GAME OVER" << endl;
	}
	else
	{
		cout << "(" << name << " 체력 : " << health << ")" << endl;
	}
}

bool Character::isDead()
{
	return health <= 0 ? true : false;
}

void Character::addExperience(int exp)
{
	if ( level < 10 )
	{
		experience += exp;
		if ( experience >= 100 )
		{
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
	cout << ">> " << name << "가(이) [★ " << item->getName() << "]을(를) 얻었습니다!" << endl;
}


vector<Item*>& Character::getInventory()
{
	return inventory;
}

void Character::setInventory(const vector<Item*>& newInventory)
{
	inventory = newInventory;
}


Character* Character::instance = nullptr;