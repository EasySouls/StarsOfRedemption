#pragma once

#include <map>
#include <vector>

#include "Item.h"

class Inventory
{
public:
	Inventory();

	void AddItem(const Item& item, size_t quantity);
	void IncreaseCapacity();

	void ListItems();

	size_t GetSize() { return m_Items.size(); }
	size_t GetCapacity() { return m_Capacity; }
	size_t GetInventoryLevel() { return m_InventoryLevel; }
private:
	std::vector<Item> m_Items;
	std::map<ItemID, int> m_ItemQuantities;

	size_t m_Capacity;
	size_t m_InventoryLevel;

	size_t m_IncreaseSize = 12;
};

