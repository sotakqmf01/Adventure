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
	BigPotion() : name("�ʴ��� ����"), price(150), healthRestore(100)
	{
		healthRestore = 100;
	};
	string getName()
	{
		return "�ʴ��� ����";
	};
	int getPrice()
	{
		return 150;
	};
};