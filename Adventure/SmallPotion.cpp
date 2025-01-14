#include <iostream>
#include "HealthPotion.h"
#include "SmallPotion.h"
using namespace std;

class SmallPotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	SmallPotion() : name("소형 물약"), price(50), healthRestore(15)
	{
	};
	string getName()
	{
		return "소형 물약";
	};
	int getPrice()
	{
		return 50;
	};
};