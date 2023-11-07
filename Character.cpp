#include "Character.h"
#include <iostream>

Character::Character(std::string firstName, std::string lastName, Class _class, Race race)
{
    m_Name = Name({ "", firstName, lastName });
    m_Class = _class;
    m_Race = race;

    switch (m_Class)
    {
    case Class::Paladin:
        m_HitDie = 10;

        m_Strength = 18;
        m_Dexterity = 12;
        m_Constitution = 16;
        m_Intelligence = 8;
        m_Wisdom = 7;
        m_Charisma = 14;
        break;
    case Class::Ranger:
        m_HitDie = 10;

        m_Strength = 12;
        m_Dexterity = 18;
        m_Constitution = 10;
        m_Intelligence = 9;
        m_Wisdom = 12;
        m_Charisma = 11;
        break;
    case Class::Wizard:
        m_HitDie = 6;

        m_Strength = 7;
        m_Dexterity = 12;
        m_Constitution = 10;
        m_Intelligence = 18;
        m_Wisdom = 15;
        m_Charisma = 13;
        break;
    default:
        break;
    }

    m_Level = 1;
    m_Exp = 0;
    m_ExpToNext = 500;

    m_MaxHp = m_HitDie + GetModifier(m_Constitution);
    m_Hp = m_MaxHp;

    m_BaseArmorClass = 10 + GetModifier(m_Dexterity);
}

int Character::GetModifier(int attr)
{
    return (attr - 10) / 2;
}

void Character::DisplayStats()
{
    std::cout << "-- Character sheet --\n" << std::endl;
    std::cout << "Name: " << GetName() << std::endl;
    std::cout << "Level: " << m_Level << std::endl;
    std::cout << "Exp: " << m_Exp << std::endl;
    std::cout << "Exp to next level: " << m_ExpToNext << std::endl;
    std::cout << std::endl;
    std::cout << "Strength: " << m_Strength << std::endl;
    std::cout << "Dexterity: " << m_Dexterity << std::endl;
    std::cout << "Constitution: " << m_Constitution << std::endl;
    std::cout << "Intelligence: " << m_Intelligence << std::endl;
    std::cout << "Wisdom: " << m_Wisdom << std::endl;
    std::cout << "Charisma: " << m_Charisma << std::endl;
    std::cout << std::endl;
    std::cout << "HP: " << m_MaxHp << " / " << m_Hp << std::endl;
    std::cout << "Armor class: " << m_BaseArmorClass << std::endl;
}

std::string Character::GetName()
{
    if (m_Name.Title == "" && m_Name.LastName == "")
    {
        return m_Name.FirstName;
    }
    else if (m_Name.Title == "") 
    {
        return m_Name.FirstName + " " + m_Name.LastName;
    }
    else 
    {
        return m_Name.Title + " " + m_Name.FirstName + " " + m_Name.LastName;
    }
}
