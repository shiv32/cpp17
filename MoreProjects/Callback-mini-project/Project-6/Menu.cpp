#include "Menu.hpp"

void Menu::RegisterMenuItem(const std::string &optionName, EventHandler handler)
{
	m_MenuItems.emplace_back(optionName, handler);
}

void Menu::DeregisterMenuItem(const std::string &optionName)
{
	std::erase_if(m_MenuItems, [&optionName](const MenuItem &menuItem)
				  { return menuItem.m_Name == optionName; });
}

void Menu::ClearMenu()
{
	m_MenuItems.clear();
}

void Menu::Run()
{
	while (true)
	{
		ClearScreen();
		if (m_PersistentHandler)
		{
			(m_pHandler->*m_PersistentHandler)(-1);
		}
		DisplayMenuItems();
		if (auto choice = GetUserChoice(); choice == 0)
		{
			if (CheckExit())
			{
				return;
			}
		}
		else
		{
			InvokeHandler(choice);
		}
		WaitForEnter();
	}
}

void Menu::RegisterPersistentHandler(EventHandler handler)
{
	m_PersistentHandler = handler;
}

void Menu::RegisterExitHandler(ExitHandler handler)
{
	m_ExitHandler = handler;
}

Menu::Menu(BaseHandler *pNumbersInput) : m_pHandler{pNumbersInput}
{
}

bool Menu::CheckExit()
{
	if (m_ExitHandler)
	{
		return (m_pHandler->*m_ExitHandler)();
	}
	return true;
}

void Menu::DisplayMenuItems()
{
	for (int i = 0; i < std::ssize(m_MenuItems); ++i)
	{
		std::cout << std::format("{}. {}\n", (i + 1), m_MenuItems[i].m_Name);
	}
}

int Menu::GetUserChoice() const
{
	std::cout << "Your choice (0 to exit)?";
	int choice{};
	std::cin >> choice;
	return choice;
}

void Menu::InvokeHandler(int choice) const
{
	if (choice > 0 && choice <= std::ssize(m_MenuItems))
	{
		auto pmf = m_MenuItems[choice - 1].m_Handler;
		(m_pHandler->*pmf)(choice);
	}
	else
	{
		std::cout << "Invalid choice. Try again!\n";
	}
}
