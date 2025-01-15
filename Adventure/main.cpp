#include "Character.h"
#include "GameManager.h"
#include "printMessage.h"
#include "printCongratulations.h"
#include <windows.h>
#include <cstdlib>
using namespace std;

int main() 
{	
	system("echo off | clip");  //   클립보드 비우기 코드. cin 에서 우클릭 방지
	UINT OriginCP = GetConsoleOutputCP(); // 클리어 메세지 출력용 변수 저장
	GameManager gameManager;
	PrintMessage printMessage;
	printMessage.printIntro();
	//PrintCongratulations printCongratulations;
	//printCongratulations.printCongratulations();

	

	// 1. 캐릭터 생성 - createCharacter()
	string name = gameManager.createCharacter();
	Character* player = Character::getInstance(name);
	printMessage.printUpperFrame();
	// 2. 전투
	while (!player->isDead()) 
	{
		gameManager.battle(player);
		Sleep(800);
		player->displayStatus();

		if (player->isDead())
			break;

		// 보스를 잡았다는 것을 확인할 수 있도록
		if (gameManager.killBoss == true)
			break;

		// 3. 상점 들릴꺼니?
		Sleep(500);
		gameManager.visitShop(player);

	}

	// 캐릭터가 사망하여 게임 종료 시 비석 메시지 출력
	if (player->isDead())
		printMessage.displayEpitaph(name);

	// 보스를 잡고 게임을 클리어 했을 때 축하 메시지 출력
	if (gameManager.killBoss == true)

		//SetConsoleOutputCP(CP_UTF8);
		//printMessage.printCongratulations();
		//SetConsoleOutputCP(OriginCP);

	// 4. 게임 종료 시 결과 출력
	gameManager.displayRPGResult();

	return 0;
}
