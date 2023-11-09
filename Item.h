#pragma once

#include <string>

enum class Rarity 
{
	Common,
	Uncommon,
	Rare,
	Magical,
	Legendary
};

enum class ItemID
{
	HEALTH_POTION,
	MANA_POTION,
	FIRE_TONIC
};

class Item
{
public:
	Item(std::string name, Rarity rarity, ItemID m_Id);

	const std::string& GetName() const { return m_Name; }
	ItemID GetID() const { return m_Id; }
private:
	std::string m_Name;
	Rarity m_Rarity;
	ItemID m_Id;
};



