#include "InventoryManager.h"

InventoryManager* InventoryManager::Instance = nullptr;

InventoryManager::InventoryManager()
{
}

InventoryManager::~InventoryManager()
{
}


int InventoryManager::GetItem(INVENTORY _Item)
{
	map<INVENTORY, int>::iterator iter = Inventory.find(_Item);

	if (iter != Inventory.end())
	{
		return (*iter).second;
	}
	return 0;
}

void InventoryManager::AddItem(INVENTORY _Item)
{
	map<INVENTORY, int>::iterator iter = Inventory.find(_Item);
	if (iter != Inventory.end())
	{
		(*iter).second++;
	}
}

void InventoryManager::UseItem(INVENTORY _Item)
{
	map<INVENTORY, int>::iterator iter = Inventory.find(_Item);
	if (iter != Inventory.end())
	{
		(*iter).second--;
	}
}
