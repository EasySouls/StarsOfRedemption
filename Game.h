#pragma once
#include "Character.h"
#include <vector>

class Game
{
public:
	Game();

	void Init();
	void MainMenu();

	// Accessors
	inline bool GetIsRunning() { return m_IsRunning; }
	inline int GetChoice() { return m_Choice; }
private:
	void Adventure();

	void CreateNewCharacter();
	bool LoadCharacter();
private:
	bool m_IsRunning;
	int m_Choice;

	std::vector<Character> m_Characters;
	int m_ActiveCharacter;
};

