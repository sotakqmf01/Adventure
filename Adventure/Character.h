#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character 
{
private:

    static Character* instance; 

    string name;                       //���谡 �̸�

    int level;                         //����

    int health;                        //���� ü��

    int maxHealth;                     //�ִ� ü��

    int attack;                        //���ݷ�

    int RemainingExperience;           //���� ����ġ

    int maxexperience;                 //�ִ� ����ġ

    int experience;                    //���� ����ġ

    int gold;                          //���

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
