#pragma once
#include <string>

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

	std::string GetName();
	inline std::string& GetFirstName() { return m_Name.FirstName; }
	inline std::string& GetLastName() { return m_Name.LastName; }
	inline std::string& GetTitle() { return m_Name.Title; }
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
};


