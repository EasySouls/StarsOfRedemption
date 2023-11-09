#pragma once

#include <string>

#include "Inventory.h"

struct Name 
{
	std::string FirstName;
	std::string LastName;
	std::string Title;
};

enum class Class 
{
	Paladin, Ranger, Wizard
	/*Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue,
	Sorcerer, Warlock, Wizard*/
};

enum class Race 
{
	Human, Elf, Dwarf
};

class Character
{
public:
	Character(std::string firstName, std::string lastName, Class _class, Race race);

	int GetModifier(int attr);

	void DisplayStats();
	void DisplayInventory();

	const std::string& GetName();
	const std::string& GetFirstName() const { return m_Name.FirstName; }
	const std::string& GetLastName() const { return m_Name.LastName; }
	const std::string& GetTitle() const { return m_Name.Title; }
private:
	Name m_Name;
	Class m_Class;
	Race m_Race;
	int m_HitDie;

	int m_Level;
	int m_Exp;
	int m_ExpToNext;

	int m_Hp;
	int m_MaxHp;

	int m_Strength;
	int m_Dexterity;
	int m_Constitution;
	int m_Intelligence;
	int m_Wisdom;
	int m_Charisma;

	int m_BaseArmorClass;

	Inventory m_Inventory;
};


