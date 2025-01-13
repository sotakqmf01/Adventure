#include "Item.h"
#include "Character.h"
#include <iostream>
#include "GenerateRandomNumber.h"
#include <vector>
#include "Shop.h"

using namespace std;

Shop::Shop() : itemlist(new ItemList())			// ������ �����۵��� �������� ����
{
	itemlist->itemlistSet();

	vector<Item*> ShopItems;

	for (int i = 0; i < 4; i++)
	{
		int e = generateRandomNumber(0, (int)itemlist->items.size() - 1);
		ShopItems.push_back(itemlist->items[e]);
	};
};


void Shop::showShop()							// ������ ������ �������� ���
{
	for (int i = 0; i < ShopItems.size(); i++)
	{
		cout << i + 1 << "��" << ShopItems[i]->getName() << " ������ : " << ShopItems[i]->getPrice() << endl;
	};
};

Item* Shop::buyItem(int index, Character* character)						// ������ ����
{
	vector<Item*> inven = character->getInventory();
	Item* item = ShopItems[index];

	if (index < 0 || index >= ShopItems.size())
	{
		cout << "�߸��� ��ȣ�Դϴ�." << endl;
		return nullptr;
	}
	if (character->getGold() > ShopItems[index]->getPrice())		// ������ �ݾ��� ���� ������ Ŭ��
	{
		character->setGold(character->getGold() - ShopItems[index]->getPrice());
		inven.push_back(ShopItems[index]);
		character->setInventory(inven);

		cout << ShopItems[index]->getName() << " ��(��) ���� �Ͽ����ϴ�." << " ������ �ݾ� : " << character->getGold() << " �� �Դϴ�." << endl;

		ShopItems.erase(ShopItems.begin() + index);
	}
	return nullptr;
};

void Shop::Reroll()								// Ȥ�� ���� ����ǵ� ������ �������� �����ϰ� �ٽ� �������� �־ ���
{
	ShopItems.clear();
	for (int i = 0; i < 4; i++)
	{
		int e = generateRandomNumber(0, (int)itemlist->items.size() - 1);
		ShopItems.push_back(itemlist->items[e]);
	};
};


Character* Shop::sellItem(int index, Character* character)				// �������� �Ǹ�
{
	vector<Item*> inven = character->getInventory();

	if (inven.empty())
	{
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return nullptr;
	}

	if (index < 0 || index >= inven.size()) 
	{
		cout << "�߸��� ��ȣ�Դϴ�. �Ǹ��� �������� �ٽ� �����ϼ���." << endl;
		return;
	}

	if (inven.size() >= 1)
	{
		int gold = inven[index]->getPrice();
		character->addGold(gold);

		cout << inven[index]->getName() << " ��(��) �Ǹ� �Ͽ����ϴ�." << " ������ �ݾ� : " << character->getGold() << " �� �Դϴ�." << endl;

		inven.erase(inven.begin() + index);
	}
	character->setInventory(inven);

	return character;
};

Shop::~Shop()
{
	delete itemlist;
}