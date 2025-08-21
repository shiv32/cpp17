#pragma once
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "NumbersInput.hpp"

inline void WaitForEnter(std::string_view msg = "Press Enter to continue...") {
	std::cout << msg << '\n';
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

inline void ClearScreen() {
	std::cout << "\033[2J\033[1;1H";
}

class Menu
{
public:
	using EventHandler = void (NumbersInput::*)(int);
	using ExitHandler = bool(NumbersInput::*)() ;

	void RegisterMenuItem(const std::string& optionName, EventHandler handler);
	void DeregisterMenuItem(const std::string &optionName);
	void ClearMenu();
	void Run();
	void RegisterPersistentHandler(EventHandler handler);
	void RegisterExitHandler(ExitHandler handler);
	Menu(NumbersInput* pNumbersInput);

private:
	bool CheckExit();
	void DisplayMenuItems();
	int GetUserChoice()const;
	void InvokeHandler(int choice)const;

	struct MenuItem {
		std::string m_Name{};
		EventHandler m_Handler{};
	};

	std::vector<MenuItem> m_MenuItems{};
	EventHandler m_PersistentHandler{} ;
	ExitHandler m_ExitHandler{} ;
	NumbersInput *m_pNumbersInput{} ;
};

