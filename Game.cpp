#include "Game.h"
#include <iostream>

Game::Game()
{
	m_IsRunning = true;
	m_Choice = 0;
	m_ActiveCharacter = 0;
}

void Game::Init()
{
	if (LoadCharacter())
		return;

	CreateNewCharacter();
}

void Game::MainMenu()
{
	Character& character = m_Characters[m_ActiveCharacter];

	std::cout << ">> ";
	std::cin >> m_Choice;

	switch (m_Choice)
	{
	case 4:
		character.DisplayStats();
		break;
	default:
		break;
	}
}

void Game::Adventure()
{
}

void Game::CreateNewCharacter()
{
	// TODO Error handling

	Name name;
	std::cout << "Enter the first name of your character: ";
	std::cin >> name.FirstName;
	std::cout << "Enter the last name of your character: ";
	std::cin >> name.LastName;

	Class _class;
	std::cout << "Select your character's class: \n";
	std::cout << "[1]: Paladin\n";
	std::cout << "[2]: Ranger\n";
	std::cout << "[3]: Wizard\n";
	std::cin >> m_Choice;

	switch (m_Choice)
	{
	case 1:
		_class = Class::Paladin;
		break;
	case 2:
		_class = Class::Ranger;
		break;
	case 3:
		_class = Class::Wizard;
		break;
	default:
		break;
	}
	
	Race race;
	std::cout << "Select your character's race: \n";
	std::cout << "[1]: Human\n";
	std::cout << "[2]: Elf\n";
	std::cout << "[3]: Dwarf\n";
	std::cin >> m_Choice;

	switch (m_Choice)
	{
	case 1:
		race = Race::Human;
		break;
	case 2:
		race = Race::Elf;
		break;
	case 3:
		race = Race::Dwarf;
		break;
	default:
		break;
	}

	m_Characters.emplace_back(name.FirstName, name.LastName, _class, race);
	m_ActiveCharacter = m_Characters.size() - 1;
}

bool Game::LoadCharacter()
{
	return false;
}

