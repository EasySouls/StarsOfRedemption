#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	m_Capacity = 12;
	m_InventoryLevel = 1;
}

void Inventory::AddItem(const Item& item, size_t quantity = 1)
{
	if (m_ItemQuantities[item.GetID()])
	{
		m_ItemQuantities[item.GetID()] += quantity;
	}
	else if (m_Items.size() <= m_Capacity)
	{
		m_Items.push_back(item);
		m_ItemQuantities[item.GetID()] += quantity;
	}
	else 
	{
		std::cout << "No more room in your inventory!" << std::endl;
	}
}

void Inventory::IncreaseCapacity()
{
	m_Capacity = m_Capacity + m_IncreaseSize;
	m_InventoryLevel += 1;
}

void Inventory::ListItems()
{
	if (m_Items.size() == 0)
	{
		std::cout << "Your inventory is empty." << std::endl;
	}

	for (Item& item: m_Items)
	{
		std::cout << item.GetName() << ", " << m_ItemQuantities[item.GetID()] << std::endl;
	}
}
