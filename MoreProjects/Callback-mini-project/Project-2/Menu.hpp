#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <format>

inline void WaitForEnter(std::string_view msg = "Press Enete to continue...")
{
    std::cout << msg << "\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

inline void ClearScreen()
{
    // Using ANSI Escape Codes (Most Unix Terminals & Modern Windows 10+)
    std::cout << "\033[2J\033[1;1H";
}

class Menu
{
public:
    using EventHandler = void (*)();
    void RegisterMenuItem(const std::string &optionName, EventHandler handler)
    {
        m_MenuItems.emplace_back(optionName, handler);
    }

    void DisplayMenuItem()
    {
        for (int i = 0; i < m_MenuItems.size(); ++i)
        {
            std::cout << std::format("{}. {}\n", (i + 1), m_MenuItems[i].m_Name);
        }
    }

    int getUserChoice()
    {
        std::cout << "Your choice (0 to exit)?";
        int choice{};
        std::cin >> choice;
        return choice;
    }

    void InvokeHandler(int choice)
    {
        if (choice > 0 && choice <= m_MenuItems.size())
        {
            m_MenuItems[choice - 1].m_Handler();
        }
        else
        {
            std::cout << "Invalid choice. Try again!\n";
        }
    }

    void Run()
    {
        while (true)
        {
            ClearScreen();
            DisplayMenuItem();

            if (int choise = getUserChoice(); choise == 0)
            {
                return;
            }
            else
            {
                InvokeHandler(choise);
            }

            WaitForEnter();
        }
    }

private:
    struct MenuItem
    {
        std::string m_Name{};
        EventHandler m_Handler{};
    };

    std::vector<MenuItem> m_MenuItems{};
};