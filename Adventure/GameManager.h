#pragma once
#include <string>

using namespace std;

class Monster;
class Character;

class GameManager
{
public:
	int totalGold = 0;
	int totalKilledMonster = 0;
	int totalUsedHealthPotion = 0;
	int totalUsedPowerPotion = 0;
	int turnCounter = 0;			// 턴 알리미
	bool killBoss = false;			// 보스 몬스터 잡으면 true
	int totalKilledBandit = 0;
	int totalKilledGoblin = 0;
	int totalKilledOrc = 0;
	int totalKilledSlime = 0;
	int totalKilledTroll = 0;
	int totalKilledBoss = 0;

public:
	string createCharacter();
	Monster* generateMonster(int level);
	Monster* generateBossMonster(int level);
	void battle(Character* player);
	void visitShop(Character* player);
	int randomGold();
	void displayRPGResult();
	void countKilledMonster(string getname);
};

