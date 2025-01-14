#include <iostream>
#include "HealthPotion.h"
using namespace std;

class BigPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	BigPotion() : name("초대형 물약"), price(150), healthRestore(100)
	{
		healthRestore = 100;
	};
	string getName()
	{
		return "초대형 물약";
	};
	int getPrice()
	{
		return 150;
	};
};