#include <iostream>
#include "HealthPotion.h"
#include "PoisonPotion.h"
using namespace std;

class PoisonPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	PoisonPotion() : name("�� ����"), price(-150), healthRestore(15)
	{
		healthRestore = -30;
	};
	string getName()
	{
		return "�� ����";
	};
	int getPrice()
	{
		return -150;
	};
};