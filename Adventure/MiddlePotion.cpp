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
	MiddlePotion() : name("���� ����"), price(75), healthRestore(30)
	{
		healthRestore = 30;
	};
	string getName()
	{
		return "���� ����";
	};
	int getPrice()
	{
		return 75;
	};
};