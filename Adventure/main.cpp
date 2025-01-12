#include "Character.h"
#include "GameManager.h"
using namespace std;

int main() {
	GameManager gameManager;
	gameManager.printIntro();
  
	// 1. 캐릭터 생성 - createCharacter()
	string name = gameManager.createCharacter();
	Character* player = Character::getInstance(name);

	// 2. 전투
	while (!player->isDead()) {

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
