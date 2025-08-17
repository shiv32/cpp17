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
    using EventHandler = void (*)(int);
    using ExitHandler = bool (*)();
    void RegisterMenuItem(const std::string &optionName, EventHandler handler)
    {
        m_MenuItems.emplace_back(optionName, handler);
    }

    void DeregisterMenuItem(const std::string &optionName)
    {
        std::erase_if(m_MenuItems, [&optionName](const MenuItem &menuItem) // C++20
                      { return menuItem.m_Name == optionName; });
    }

    void ClearMenu()
    {
        m_MenuItems.clear();
    }

    void Run()
    {
        while (true)
        {
            ClearScreen();

            if (m_PersistentHandler)
            {
                m_PersistentHandler(-1);
            }

            DisplayMenuItem();

            if (int choise = getUserChoice(); choise == 0)
            {
                if (CheckExit())
                {
                    return;
                }
            }
            else
            {
                InvokeHandler(choise);
            }

            WaitForEnter();
        }
    }

    void RegisterPersistentHandler(EventHandler handler)
    {
        m_PersistentHandler = handler;
    }

    void RegisterExitHandler(ExitHandler handler)
    {
        m_Exithandler = handler;
    }

private:
    bool CheckExit()
    {
        if (m_Exithandler)
        {
            return m_Exithandler();
        }

        return true;
    }

    void DisplayMenuItem()
    {
        for (int i = 0; i < std::ssize(m_MenuItems); ++i) // C++20
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
        if (choice > 0 && choice <= std::ssize(m_MenuItems))
        {
            m_MenuItems[choice - 1].m_Handler(choice);
        }
        else
        {
            std::cout << "Invalid choice. Try again!\n";
        }
    }

    struct MenuItem
    {
        std::string m_Name{};
        EventHandler m_Handler{};
    };

    std::vector<MenuItem> m_MenuItems{};
    EventHandler m_PersistentHandler{};
    ExitHandler m_Exithandler{};
};