#include <iostream>
#include "Menu.hpp"

std::vector<int> numbers{};

bool IsValidIndex(int index)
{
    return (index < 0 || (index >= std::ssize(numbers)));
}

void OnAdd(int choice)
{
    int x{};
    std::cout << "Enter the number to add:";
    std::cin >> x;
    numbers.push_back(x);
    std::cout << std::format("{} added to the list\n", x);
}

void OnGenerateRandom(int choice)
{
    int count{};
    std::cout << "How many random numbers to generate? ";
    std::cin >> count;
    numbers.clear();
    for (int i = 0; i < count; ++i)
    {
        numbers.push_back(rand() % 100);
    }
    std::cout << "Generated " << count << " random numbers.\n";
}

void OnUpdate(int choice)
{
    if (numbers.empty())
    {
        std::cout << "no numbers to update\n"
                  << std::endl;
        return;
    }

    std::cout << "Enter the index of the number to update:";
    int index{};
    std::cin >> index;
    if (IsValidIndex(index))
    {
        std::cout << "Invalid index!\n";
        return;
    }

    std::cout << "Enter new value:";
    int newValue{};
    std::cin >> newValue;
    auto oldValue = numbers[index];
    numbers[index] = newValue;
    std::cout << std::format("Update index {} from {} to {}\n", index, oldValue, newValue);
}

void OnInsert(int choice)
{
    int index{};
    std::cout << "Enter index to insert at: ";
    std::cin >> index;
    if (index < 0 || index > numbers.size())
    {
        std::cout << "Invalid index!\n";
        return;
    }
    int x{};
    std::cout << "Enter a number to insert: ";
    std::cin >> x;
    numbers.insert(numbers.begin() + index, x);
    std::cout << std::format("Inserted {} at index {}.\n", x, index);
}
void OnRemove(int choice)
{
    if (numbers.empty())
    {
        std::cout << "No numbers to remove.\n";
        return;
    }
    int x{};
    std::cout << "Enter the index : ";
    std::cin >> x;
    if (x < 0 || x >= numbers.size())
    {
        std::cout << "Invalid index!\n";
        return;
    }
    int removedValue = numbers[x];
    numbers.erase(numbers.begin() + x);
    std::cout << "Removed " << removedValue << " from the list.\n";
}
void OnRemoveAll(int choice)
{
    if (numbers.empty())
    {
        std::cout << "No numbers to remove.\n";
        return;
    }
    numbers.clear();
    std::cout << "Removed all numbers from the list.\n";
}
void OnDisplay(int choice)
{
    if (numbers.empty())
    {
        std::cout << "No numbers to display.\n";
        return;
    }
    std::cout << "Numbers in the list: ";
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

bool OnExit()
{
    if (numbers.empty())
    {
        return true;
    }
    std::cout << "List is not empty!\n";
    return false;
}

int main()
{
    Menu menu{};
    menu.RegisterPersistentHandler(OnDisplay);
    menu.RegisterExitHandler(OnExit);
    menu.RegisterMenuItem("Generate random numbers", OnGenerateRandom);
    menu.RegisterMenuItem("Add a number", OnAdd);
    menu.RegisterMenuItem("Update a number", OnUpdate);
    menu.RegisterMenuItem("Insert a number", OnInsert);
    menu.RegisterMenuItem("Remove a number", OnRemove);
    menu.RegisterMenuItem("Remove all numbers", OnRemoveAll);
    // menu.RegisterMenuItem("Display all numbers", OnDisplay);
    menu.Run();

    return 0;
}