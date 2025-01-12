#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Slime.h"
#include "Orc.h"
#include "Item.h"
#include "GenerateRandomNumber.h"

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

	switch (generateRandomNumber(0, 1)) {
	case 0:
		monster = new Slime(level);
		break;
	case 1:
		monster = new Orc(level);
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

void GameManager::displayRPGResult()
{
	char lookResult;
	cout << "���� ����� ���ðڽ��ϱ�? (Y/N) : ";
	cin >> lookResult;
	if (lookResult == 'y' || lookResult == 'Y') {
		system("cls");
		cout << "=============���� ���=============" << endl;
		cout << "> ���� óġ �� : " << totalKilledMonster << endl;
		cout << "> ȹ�� ��差 : " << totalGold << endl;
		cout << "==================================" << endl;
	}
}
