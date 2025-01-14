#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"
#include "Shop.h"
#include "printMessage.h"
#include "conio.h"

using namespace std;

Character::Character(const string& name)
	: name(name), level(1), health(2000), maxHealth(2000), attack(300), experience(0), maxExperience(100), gold(200), remainingExperience(0)
{
	cout << name << " 생성 :" << " 레벨, " << level << "체력: " << health << "/" << maxHealth << "경험치: " << experience << "/" << maxExperience << "골드: " << gold << endl;
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
  	PrintMessage printMessage;

	if (health == 0)  //캐릭터 사망시 출력
	{
		printMessage.printFrame();
		cout << "여기까지인가......" << endl;
	}
	else
	{
		printMessage.printFrame();
		cout << "-------------------------------------------------" << endl;
		printMessage.printFrame();
		cout << " 레벨: " << level << endl;
		printMessage.printFrame();
		cout << " 체력: " << health << "/" << maxHealth << endl;
		printMessage.printFrame();
		cout << " 골드: " << gold << endl;
		printMessage.printFrame();
		cout << " 대미지: " << attack << endl;
		printMessage.printFrame();
		cout << " 경험치: " << experience << "/" << maxExperience << endl;
		printMessage.printFrame();
		cout << "-------------------------------------------------" << endl;
		showInventory();
	 }  
}

void Character::levelUp()													
{
	if (experience >= 100)											
	{	
		PrintMessage printMessage;
		int addhealth;				//증가한 체력
		level++;						
		addhealth = level * 13;
		maxHealth += addhealth;		//level * 13 -> addhealth
		health = maxHealth;
		attack += level * 2;
		experience = 0;													
		experience += remainingExperience;
		maxExperience += level * 1;
	
		cout << "          |       |                                                                                     |       |" << endl;
		printMessage.printFrame();
		cout << "************************************************" << endl;
		printMessage.printFrame();
		cout << "  ##        ##     ##      ##     ## ########  " << endl;
		printMessage.printFrame();
		cout << "  ##        ##     ##      ##     ## ##     ## " << endl;
		printMessage.printFrame();
		cout << "  ##        ##     ##      ##     ## ##     ## " << endl;
		printMessage.printFrame();
		cout << "  ##        ##     ##      ##     ## ########  " << endl;
		printMessage.printFrame();
		cout << "  ##         ##   ##       ##     ## ##        " << endl;
		printMessage.printFrame();
		cout << "  ##          ## ##        ##     ## ##      " << endl;
		printMessage.printFrame();
		cout << "  ########     ###          #######  ##    " << endl;
		printMessage.printFrame();
		cout << "************************************************" << endl;
		printMessage.printFrame();
		cout << "  공격력 " << level * 2 << "증가, 체력 " << addhealth << "증가" << endl;		//
		printMessage.printFrame();
		cout << "  다음 레벨까지 " << maxExperience << "경험치 필요" << endl;					//변경
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

			if (inventory[index] != nullptr)
			{
				inventory[index]->use(instance);
			}
			// 사용하고나면 벡터에서 삭제
			inventory.erase(inventory.begin() + index);
		}
	}
}

void Character::showInventory()
{

	PrintMessage printMessage;

	printMessage.printFrame();
	cout << "        - I N V E N T O R Y -" << endl;

	if (inventory.size() < 1)
	{
		printMessage.printFrame();;
		cout << "      인벤토리가 비어 있습니다." << endl;
	}
	else
	{
		sortInventoryByName();
		for (size_t i = 0; i < inventory.size(); ++i)
		{		
			printMessage.printFrame();
			cout << i + 1 << ". " << inventory[i]->getName() << endl;
		}
		printMessage.printFrame();
		cout << endl;
	}
	printMessage.printFrame();
	cout << "-----------------------------" << endl;
}

void Character::sortInventoryByName()                 //정렬
{
	sort(inventory.begin(), inventory.end(), [](Item* a, Item* b) 
		{
		return a->getName() < b->getName(); // 이름을 기준으로 오름차순 정렬?
		});
}

void Character::enhanceAttack(int attackIncrease)
{
	PrintMessage printMessage;
	//printMessage.textColor(6);
	//cout << "          |       |                                                                                     |       |";
	//printMessage.textColor(7);
	//printMessage.gotoXY(26, printMessage.getcursorlocationY());
	attack += attackIncrease;
	if (attack <= 0)
	{
		attack = 0;				//공격력 음수 방지
	}
	cout << " (" << attack - attackIncrease << " -> " << attack << ")" << endl;

}

void Character::Heal(int heal)
{
	health += heal;
	if (health > maxHealth)
	{
		health = maxHealth;
	PrintMessage printMessage;
	//printMessage.textColor(6);
	//cout << "          |       |                                                                                     |       |";
	//printMessage.textColor(7);
	//printMessage.gotoXY(26, printMessage.getcursorlocationY());
	cout << " (" << health - heal << " -> " << health << ")" << endl;
  }  

}

void Character::takeDamage(int damage)
{
	PrintMessage printMessage;
	
	health -= damage;
	if ( health <= 0 )
	{
		health = 0;
		cout << "(" << name << " 체력 : " << health << ")" << endl;
		printMessage.printFrame();
		cout << "-------------------------------------------------" << endl;
		printMessage.printFrame();
		cout << ">> ㅠㅠ " << name << "가(이) 사망했습니다. GAME OVER" << endl;
		_getch();
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
		if (experience >= maxExperience)					//100 -> maxexperience
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
	PrintMessage printMessage;

	inventory.push_back(item);

	printMessage.printFrame();
	cout << ">> " << name << "가(이) [★ " << item->getName() << "]을(를) 얻었습니다!" << endl;
	//if (inventory.size() > 9)              //최대 인벤토리10
	//{
	//	cout << ">> " << name << "가(이) [★ " << item->getName() << "]을(를) 얻었지만" << endl << "인벤토리가 가득 찼습니다!" << endl; 
	//}
	//else
	//{
	//	inventory.push_back(item);
	//	cout << ">> " << name << "가(이) [★ " << item->getName() << "]을(를) 얻었습니다!" << endl;
	//}
}

vector<Item*>& Character::getInventory()
{
	return inventory;
}

Character* Character::instance = nullptr;
