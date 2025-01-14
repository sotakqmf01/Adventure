#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"

using namespace std;

Character::Character(const string& name)
	: name(name), level(1), health(200), maxHealth(200), attack(300), experience(0), maxexperience(100), gold(0)
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
	cout << " 경험치: " << experience << "/" << maxexperience << endl;
	showInventory();
}

void Character::levelUp()
{
	if (experience >= 100)
	{
		level++;
		maxHealth += level * 13;
		health = maxHealth;
		attack += level * 2;
		experience = 0;
		experience += RemainingExperience;
		maxexperience += level * 25;
		cout << "*************************************************" << endl;
		cout << "##        ##     ##      ##     ## ########  "<< endl;
		cout << "##        ##     ##      ##     ## ##     ## " << endl;;
		cout << "##        ##     ##      ##     ## ##     ## " << endl;;
		cout << "##        ##     ##      ##     ## ########  " << endl;;
		cout << "##         ##   ##       ##     ## ##        " << endl;
		cout << "##          ## ##        ##     ## ##      " << endl;
		cout << "########     ###          #######  ##    " << endl;
		cout << "*************************************************" << endl;

	}
}

void Character::useRandomItem()
{
	// 아이템이 있으면 랜덤 사용
	if (inventory.size() >= 1)
	{
		// 30%로아이템 사용
		if (generateRandomNumber(0, 99) < 30)
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
	if ( inventory.size() < 1 )
	{
		cout << "        인벤토리가 비어 있습니다." << endl;
	}
	else
	{
		for ( size_t i = 0; i < inventory.size(); ++i )
		{
			cout << "        " << i + 1 << ". " << inventory[ i ]->getName() << endl;
		}
	}
}


void Character::enhanceAttack(int attackIncrease)
{
	attack += attackIncrease;
}

void Character::Heal(int heal)
{
	health = +heal;
	if (health > maxHealth)
	{
		health = maxHealth;
	}
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)

	{
		health = 0;
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
		if (experience >= maxexperience)
		{
			RemainingExperience = experience - maxexperience;
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
}

Character* Character::instance = nullptr;