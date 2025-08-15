#include <iostream>
#include <format>
#include "math_func.hpp"

void WaitForEnter(std::string_view msg = "Press Enete to continue...")
{
    std::cout << msg << "\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void ClearScreen()
{
    // Using ANSI Escape Codes (Most Unix Terminals & Modern Windows 10+)
    std::cout << "\033[2J\033[1;1H";
}

void OnIncrement()
{
    std::cout << "Enter value to Increment:";
    int value{};
    std::cin >> value;
    auto result = Increment(value);
    std::cout << std::format("Increment of {} by 1 is {}\n", value, result); // C++20
}

void OnDouble()
{
    std::cout << "Enter value to Double:";
    int value{};
    std::cin >> value;
    auto result = Double(value);
    std::cout << std::format("Double of {} is {}\n", value, result); // C++20
}

void OnSquare()
{
    std::cout << "Enter value to Square:";
    int value{};
    std::cin >> value;
    auto result = Square(value);
    std::cout << std::format("Square of {} is {}\n", value, result); // C++20
}

void Menu()
{
    while (true)
    {
        std::cout << "1. Square\n";
        std::cout << "2. Double\n";
        std::cout << "3. Increment\n";
        std::cout << "Your choice (0 to exit)?";

        int choice{};
        std::cin >> choice;

        if (choice == 0)
        {
            return;
        }

        switch (choice)
        {
        case 1:
        {
            OnSquare();
        }
        break;
        case 2:
        {
            OnDouble();
        }
        break;
        case 3:
        {
            OnIncrement();
        }
        break;
        default:
            std::cout << "Invalid option. Please try again!\n";
            break;
        }

        WaitForEnter();
        ClearScreen();
    }
}

int main()
{
    Menu();

    return 0;
}