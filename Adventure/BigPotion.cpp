#include <iostream>
#include "HealthPotion.h"
#include "BigPotion.h"
using namespace std;


BigPotion::BigPotion() : name("�ʴ��� ����"), price(150), healthRestore(100)
	{
		healthRestore = 100;
	};
	string BigPotion::getName()
	{
		return "�ʴ��� ����";
	};
int BigPotion:: getPrice()
	{
		return 150;
	};