#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Slime.h"
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"
#include "BossMonster.h"
#include "Item.h"
#include "GenerateRandomNumber.h"

void GameManager::textColor(unsigned short color)	// �÷� �ؽ�Ʈ �Լ� 0(������)~15(���� �Ͼ��)���� �Է�
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void GameManager::printIntro()
{
	textColor(12);
	cout << "_________";
	textColor(7);
	cout << "______     __    ______     ";
	textColor(9);	
	cout << "_______  ______            _______  _       _________          _______  _______ " << endl;
	textColor(12);
	cout << "\\__   __/";
	textColor(7);
	cout << "(  __  \\   /__\\  (  __  \\   "; 
	textColor(9); 
	cout << "(  ___  )(  __  \\ |\\     /|(  ____ \\( (    /|\\__   __/|\\     /|(  ____ )(  ____ \\" << endl;
	textColor(12);
	cout << "   ) (   ";
	textColor(7); 
	cout << "| (  \\  ) ( \\/ ) | (  \\  )  ";
	textColor(9); 
	cout << "| (   ) || (  \\  )| )   ( || (    \\/|  \\  ( |   ) (   | )   ( || (    )|| (    \\/" << endl;
	textColor(12);
	cout << "   | |   ";
	textColor(7); 
	cout << "| |   ) |  \\  /  | |   ) |  "; 
	textColor(9); 
	cout << "| (___) || |   ) || |   | || (__    |   \\ | |   | |   | |   | || (____)|| (__    " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| |   | |  /  \\/\\| |   | |  ";
	textColor(9); 
	cout << "| ___  || |   | |(()) | __) | (\\ \\) |   | |   | |   | ||     __) | __)   " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| |   ) | / /\\  /| |   ) |  "; 
	textColor(9); 
	cout << "| (   ) || |   ) | \\ \\_/ / | (      | | \\   |   | |   | |   | || (\\ (   | (      " << endl;
	textColor(12);
	cout << "   | |   "; 
	textColor(7); 
	cout << "| (__/  )(  \\/  \\| (__/  )  "; 
	textColor(9); 
	cout << "| )   ( || (__/  )  \\   /  | (____/\\| )  \\  |   | |   | (___) || ) \\ \\__| (____/\\" << endl;
	textColor(12);
	cout << "   )_(   "; 
	textColor(7); 
	cout << "(______/  \\___/\\/(______/   "; 
	textColor(9); 
	cout << "|/     \\|(______/    \\_/   (_______/|/    )_)   )_(   (_______)|/   \\__/(_______/" << endl;
	textColor(7);
	Sleep(3000);
}

string GameManager::createCharacter()
{
	string name;
	cout << "============================================" << endl;
	cout << "            ȯ���մϴ�. ���谡��!\n";
	cout << "============================================" << endl;
	cout << " ĳ���͸��� �Է��ϼ��� : ";
	getline(cin, name);			// �̸��� �����̸� �ٽ� �Է��ϵ����ϴ� �κ� ���߿� �߰�?
	cout << endl;

	Character* player = Character::getInstance(name);
	cout << "        ** ĳ���� [" << name << "] ���� �Ϸ�! **" << endl;
	player->displayStatus();

	return name;
}

Monster* GameManager::generateMonster(int level)
{
	Monster* monster = nullptr;

	switch (generateRandomNumber(0, 3)) {
	case 0:
		monster = new Slime(level);
		break;
	case 1:
		monster = new Orc(level);
		break;
	case 2:
		monster = new Goblin(level);
		break;
	case 3:
		monster = new Troll(level);
		break;
	default:
		break;
	}

	return monster;
}

void GameManager::battle(Character* player)
{
	Monster* monster = generateMonster(player->getLevel());
	Sleep(2000);
	//system("cls");

	cout << "*************************************************" << endl;
	cout << "          " << monster->getName()
		<< " �߰� (HP:" << monster->getHealth() << ", DAMAGE:" << monster->getAttack() << ")" << endl;
	cout << "*************************************************" << endl;

	while (!player->isDead() && !monster->isDead()) {
		// �÷��̾� -> ���� ����
		cout << " " << player->getName() << "��(��) " << monster->getName() << "��(��) ����!  ";
		monster->takeDamage(player->getAttack());

		// ���Ͱ� ������ ����ġ�� ��� ȹ��, ���� �����۵� ��� + ���� ����
		if (monster->isDead()) {
			// ������ ���(����) �� ������ ȹ��(�÷��̾�)
			cout << "-------------------------------------------------" << endl;
			Item* dropedItem = monster->dropItem();
			if (dropedItem != nullptr)
				player->getDropedItem(dropedItem);

			// ����ġ �� ��� ȹ��
			int gainGold = randomGold();
			cout << ">> " << player->getName() << "��(��) 50EXP�� " << gainGold << " ��带 ȹ��" << endl;
			player->addExperience(50);
			player->addGold(gainGold);

			totalGold += gainGold;
			totalKilledMonster++;

			delete monster;
			break;
		}

		// 30% Ȯ���� ������ ��� -> �׳� useRandomItem�� Ȯ�������� ����ϵ��� �ұ�?
		if (generateRandomNumber(1, 100) <= 30) {
			player->useRandomItem();
		}

		// ���� -> �÷��̾� ����
		cout << " " << monster->getName() << "��(��) " << player->getName() << "��(��) ����!  ";
		player->takeDamage(monster->getAttack());

		// �÷��̾ ������ ���� ����
		if (player->isDead()) {
			break;
		}
	}
}

void GameManager::visitShop(Character* player)
{
	char visitShop;
	cout << "������ �湮�Ͻðڽ��ϱ�? (Y/N) : ";
	cin >> visitShop;
	if (visitShop == 'y' || visitShop == 'Y') {

	}
}

int GameManager::randomGold()
{
	return generateRandomNumber(10, 20);
}
