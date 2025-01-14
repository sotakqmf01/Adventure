#include <iostream>
#include "HealthPotion.h"
using namespace std;

class LagePotion : public HealthPotion
{
protected:
	string name;
	int healthRestore;
	int price;
public:
	LagePotion() : name("대형 물약"), price(100), healthRestore(50)
	{
		healthRestore = 50;
	};
	string getName()
	{
		return "대형 물약";
	};
	int getPrice()
	{
		return 100;
	};
};