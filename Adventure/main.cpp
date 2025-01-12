#include "Character.h"
#include "GameManager.h"
using namespace std;

int main() {
	GameManager gameManager;

	// 1. ĳ���� ���� - createCharacter()
	string name = gameManager.createCharacter();
	Character* player = Character::getInstance(name);

	// 2. ����
	while (!player->isDead()) 
	{
		gameManager.battle(player);
		player->displayStatus();

		// 3. ���� �鸱����?
		gameManager.visitShop(player);
	}

	// 4. ĳ���� ��� �� ���� ����
	// ���� ���� �� ��� ���
	if (player->isDead())
	{
		gameManager.displayRPGResult();
	}

	return 0;
}