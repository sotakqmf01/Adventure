#include <iostream>
#include "Character.h"
#include "GenerateRandomNumber.h"
#include "Shop.h"
#include "printMessage.h"
#include "conio.h"

using namespace std;

Character::Character(const string& name)

	: name(name), level(1), health(200), maxHealth(200), attack(30), experience(0), maxExperience(100), gold(80), remainingExperience(0)


{
	if (name == "창민")
	{
		level = 5;
		health = 9999;
		maxHealth = 9999;
		attack = 9999;
		gold = 0;
	}

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

	if (health <= 0)  //캐릭터 사망시 출력
	{
		printMessage.printFrame();
		cout << endl;
		printMessage.printFrame();
		cout << endl;
		printMessage.printFrame();
		cout << "			   여기까지인가......" << endl;
		printMessage.printFrame();
		cout << endl;
		printMessage.printFrame();
		cout << endl;
	}
	else
	{
		printMessage.printFrame();
		printMessage.textColor(1);
		cout << "      _,.-'~'-.,__,.-'~'-."; printMessage.textColor(144); cout << " S T A T U S "; printMessage.textColor(1); cout << ".-'~'-.,__,.-'~'-.,_" << endl;
		printMessage.printFrame();
		cout << "       레벨:   " << level << endl;
		printMessage.printFrame();
		cout << "       체력:   " << health << "/" << maxHealth << endl;
		printMessage.printFrame();
		cout << "       골드:   " << gold << endl;
		printMessage.printFrame();
		cout << "       데미지: " << attack << endl;
		printMessage.printFrame();
		cout << "       경험치: " << experience << "/" << maxExperience << endl;
		printMessage.printFrame();
		printMessage.textColor(1);
		cout << "      _,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.," << endl;
		printMessage.textColor(7);
		Sleep(500);
		showInventory();
	 }  
}

void Character::levelUp()													
{
	if (experience >= 100)											
	{	
		PrintMessage printMessage;
		int addhealth;				//증가한 체력
		int addattack;              //증가한 공격력 변수
		level++;						
		addhealth = level * 15;
		maxHealth += addhealth;		//level * 13 -> addhealth
		health = maxHealth;
		addattack = level * 5;     //공격력 증가
		attack += addattack;        
		experience = 0;													
		experience += remainingExperience;
		maxExperience += level * 3;
		printMessage.textColor(6);
		cout << "          |       |                                                                                     |       |" << endl;
		printMessage.printFrame();
		cout << "         ************************************************" << endl;
		printMessage.printFrame();
		cout << "           ##        ##     ##      ##     ## ########  " << endl;
		printMessage.printFrame();
		cout << "           ##        ##     ##      ##     ## ##     ## " << endl;
		printMessage.printFrame();
		cout << "           ##        ##     ##      ##     ## ##     ## " << endl;
		printMessage.printFrame();
		cout << "           ##        ##     ##      ##     ## ########  " << endl;
		printMessage.printFrame();
		cout << "           ##         ##   ##       ##     ## ##        " << endl;
		printMessage.printFrame();
		cout << "           ##          ## ##        ##     ## ##      " << endl;
		printMessage.printFrame();
		cout << "           ########     ###          #######  ##    " << endl;
		printMessage.printFrame();
		cout << "         ************************************************" << endl;
		printMessage.printFrame();
		cout << "              공격력 " << addattack << " 증가, 체력 " << addhealth << " 증가" << endl;		//
		printMessage.printFrame();
		cout << "                 다음 레벨까지 " << maxExperience << " 경험치 필요" << endl;					//변경
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
	cout << endl;
	printMessage.printFrame();
	printMessage.textColor(7);
	cout << "      ##=##=##=##=##=##=##=#"; printMessage.textColor(112); cout << "INVENTORY"; printMessage.textColor(7);cout << "=##=##=##=##=##=##=##=" << endl;
	
	printMessage.textColor(7);
	if (inventory.size() < 1)
	{
		printMessage.printFrame();;
		cout << "            인벤토리가 비어 있습니다." << endl;
	}
	else
	{
		sortInventoryByName();
		for (size_t i = 0; i < inventory.size(); ++i)
		{		
			printMessage.printFrame();
			cout << "            " << i + 1 << ". " << inventory[i]->getName() << endl;
		}
		printMessage.printFrame();
		cout << endl;
	}
	printMessage.printFrame();
	printMessage.textColor(7);
	cout << "      ##=##=##=##=##=##=##=##=##=##=##=##=##=##=##=##=##=##" << endl;
	printMessage.textColor(7);
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
	attack += attackIncrease;
	if (attack <= 0)
	{
		attack = 0;				//공격력 음수 방지
	}

	cout << " (공격력 : " << attack - attackIncrease << " -> " << attack << ")" << endl;
}

void Character::Heal(int heal)
{
	int prevHealth = health;
	
	if (heal >= 0)
	{
		health += heal;

		if (health > maxHealth)
		{
			health = maxHealth;
		}

		cout << " (체력 : " << prevHealth << " -> " << health << ")" << endl;
	}
	else
	{
		takeDamage(-heal);
	}
}

void Character::takeDamage(int damage)
{
	PrintMessage printMessage;
	
	int prevHealth = health;

	health -= damage;
	if ( health <= 0 )
	{
		health = 0;
		cout << "(" << name << " 체력 : " << prevHealth << " → " << health << ")" << endl;
		printMessage.printFrame();
		cout << endl;
		printMessage.printFrame();
		printMessage.textColor(1);
		cout << "      _,.-'~'-.,__,.-'~'-."; printMessage.textColor(144); cout << " S T A T U S "; printMessage.textColor(1); cout << ".-'~'-.,__,.-'~'-.,_" << endl;
		printMessage.textColor(7);
		printMessage.printFrame();
		cout << "      >> ㅠㅠ " << name << "가(이) 사망했습니다. GAME OVER" << endl;
		_getch();
	}
	else
	{
		cout << "(" << name << " 체력 : " << prevHealth << " → " << health << ")" << endl;
	}
}
bool Character::isLoseweapon()  // 플레이어 공격력 0 감지
{
	return attack <= 0;
}
bool Character::isDead()
{
	return health <= 0;
}

void Character::addExperience(int exp, Item* item)
{
	if (level < 10) 
	{
		PrintMessage printMessage;

		experience += exp;

		if (item != nullptr) // 레벨 10 이전에 경험치 책 사용
		{
			cout << " (경험치 : " << experience - exp << " -> " << experience << ")" << endl;
		}

		if (experience >= maxExperience)
		{
			remainingExperience = experience - maxExperience;
			levelUp();
		}
	}
	else // 레벨 10일때 경험치 책 사용했을 경우
	{
		if (item != nullptr)
		{
			cout << "  효과가 없었습니다." << endl;
		}
	}
}

void Character::addGold(int _gold)
{
	gold += _gold;
	if (gold <= 0) 
	{
		gold = 0;             //골드 음수 방지
	}
}

void Character::getDropedItem(Item* item)
{
	PrintMessage printMessage;

	if (inventory.size() >= 20)              
	{
		printMessage.printFrame();
		cout << "      >> 인벤토리가 가득 차 [★ " << item->getName() << "]을(를) 얻지 못하였습니다" << endl; 
	
		delete item;
	}
	else
	{
		inventory.push_back(item);

		printMessage.printFrame();
		cout << "      >> " << name << "가(이) [★ " << item->getName() << "]을(를) 얻었습니다!" << endl;
	}
}

vector<Item*>& Character::getInventory()
{
	return inventory;
}

Character* Character::instance = nullptr;