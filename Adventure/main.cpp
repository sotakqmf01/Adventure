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

		if (player->isDead())
			break;

		// 보스를 잡았다는 것을 확인할 수 있도록
		if (gameManager.killBoss == true)
			break;

		// 3. 상점 들릴꺼니?
		gameManager.visitShop(player);
	}

	// 캐릭터가 사망한게 아닌 보스를 잡고 게임을 클리어 했을 때 축하 메시지 출력
	if (gameManager.killBoss == true)
		gameManager.printCongratulations();

	// 4. 게임 종료 시 결과 출력
	gameManager.displayRPGResult();

	return 0;
}
