#pragma once
#include <string>
#include <vector>
using namespace std;

class Character;

class Item
{
public:
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual void use(Character* character) = 0;
};


class ItemList
{
public:
	vector<Item*> items;		//������ ���
	ItemList();					//������ ��� ����
	~ItemList();
	void additem(Item* item);	// ������ �߰�

};
