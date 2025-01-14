#include <iostream>
#include "HealthPotion.h"
using namespace std;

class MiddlePotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	MiddlePotion() : name("중형 물약"), price(75), healthRestore(30)
	{
		healthRestore = 30;
	};
	string getName()
	{
		return "중형 물약";
	};
	int getPrice()
	{
		return 75;
	};
};