#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"
#include "Shop.h"
using namespace std;

Character::Character(const string& name)
	: name(name), level(1), health(200), maxHealth(200), attack(30),
	remainingExperience(0), maxExperience(100), experience(0), gold(0)
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " 레벨: " << level << endl;
	cout << " 체력: " << health << "/" << maxHealth << endl;
	cout << " 골드: " << gold << endl;
	cout << " 대미지: " << attack << endl;
	cout << " 경험치: " << experience << "/" << maxExperience << endl;
	showInventory();
}

void Character::levelUp()
{
	level++;
	maxHealth += level * 13;
	health = maxHealth;
	attack += level * 2;
	experience = 0;
	if (level < 10)
	{
		experience += remainingExperience;
	}
	maxExperience += level * 25;
	cout << "************************************************" << endl;
	cout << "  ##        ##     ##      ##     ## ########  " << endl;
	cout << "  ##        ##     ##      ##     ## ##     ## " << endl;;
	cout << "  ##        ##     ##      ##     ## ##     ## " << endl;;
	cout << "  ##        ##     ##      ##     ## ########  " << endl;;
	cout << "  ##         ##   ##       ##     ## ##        " << endl;
	cout << "  ##          ## ##        ##     ## ##      " << endl;
	cout << "  ########     ###          #######  ##    " << endl;
	cout << "************************************************" << endl << endl;
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
	cout << endl;
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
	return health <= 0;
}

void Character::addExperience(int exp)
{
	if (level < 10) {
		experience += exp;
		if (experience >= maxExperience)
		{
			remainingExperience = experience - maxExperience;
			levelUp();
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