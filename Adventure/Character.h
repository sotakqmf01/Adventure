#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character 
{
private:

    static Character* instance; 

    string name;                       //모험가 이름

    int level;                         //레벨

    int health;                        //현재 체력

    int maxHealth;                     //최대 체력

    int attack;                        //공격력

    int RemainingExperience;           //남은 경험치

    int maxexperience;                 //최대 경혐치

    int experience;                    //보유 경험치

    int gold;                          //골드

    vector<Item*> inventory;

    Character(const string& name);

public:

    static Character* getInstance(const string& name);

    void displayStatus();

    void levelUp();

    void useRandomItem();

    void enhanceAttack(int attackIncrease);

    void Heal(int heal);

    void takeDamage(int damage);

    bool isDead();

    void addExperience(int exp);

    void addGold(int _gold);

    void getDropedItem(Item* item);

    void showInventory();

    int getLevel()
    {
        return level;
    }

    string& getName()
    {
        return name;
    }

    int getAttack()
    {
        return attack;
    }

};
