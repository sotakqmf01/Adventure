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
	PoisonPotion() : name("독 물약"), price(-150), healthRestore(15)
	{
		healthRestore = -30;
	};
	string getName()
	{
		return "독 물약";
	};
	int getPrice()
	{
		return -150;
	};
};