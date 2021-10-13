#pragma once
#include "Headers.h"

class InventoryManager
{
private:
	static InventoryManager* Instance;
public:
	static InventoryManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InventoryManager;
		return Instance;
	}
private:
	 map<INVENTORY, int> Inventory;

public:
	map<INVENTORY, int>* GetInventory() { return &Inventory; }
	void SetInventory(const map < INVENTORY, int>& _Inventory) { Inventory = _Inventory; }

	int GetItem(INVENTORY _Item);
	void AddItem(INVENTORY _Item);
	void AddItem(INVENTORY _Item,int _Count);
	void UseItem(INVENTORY _Item);
	void UseItem(INVENTORY _Item,int Count);

private:
	InventoryManager();
public:
	~InventoryManager();
};

