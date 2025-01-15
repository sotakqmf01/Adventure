#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Character;

class Item
{
public:
	virtual ~Item() {}
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual void use(Character* character) = 0;
};

class ItemList
{
public:
	vector<Item*> items;
	ItemList();                 // ?„ì´??ëª©ë¡
	void additem(Item* item);	// ?„ì´??ì¶”ê?;			
	~ItemList();				// ?Œë©¸??
};