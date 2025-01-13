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
	vector<Item*> items;		//아이템 목록
	ItemList();					//아이템 목록 생성
	~ItemList();
	void additem(Item* item);	// 아이템 추가

};
