/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map Inserting Elements
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <map>

class Data final
{
public:
    explicit Data(int value = 0) : mValue(value) {}
    int getValue() const { return mValue; }
    void setValue(int value) { mValue = value; }

private:
    int mValue;
};

void printMap(const std::map<int, Data> &dataMap)
{
    // Print keys and values
    for (const auto &pair : dataMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second.getValue() << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::map<int, Data> dataMap;

    // initializer_list
    auto ret = dataMap.insert({1, Data(4)});

    /*

        The type of the ret variable is a pair as follows:

        pair<map<int, Data>::iterator, bool> ret;

    */

    if (ret.second)
    {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Insert failed!" << std::endl;
    }

    printMap(dataMap);

    // Using a pair object
    ret = dataMap.insert(std::make_pair(1, Data(6)));

    if (ret.second)
    {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Insert failed!" << std::endl;
    }

    // initializers for if statements (C++17)
    if (auto result = dataMap.insert({1, Data(4)}); result.second)
    {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Insert failed!" << std::endl;
    }

    // C++17 structured bindings
    if (auto [iter, success] = dataMap.insert({1, Data(4)}); success)
    {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else
    {
        std::cout << "Insert failed!" << std::endl;
    }

    // insert_or_assign
    ret = dataMap.insert_or_assign(1, Data(7));

    if (ret.second)
    {
        std::cout << "Inserted." << std::endl;
    }
    else
    {
        std::cout << "Overwritten." << std::endl;
    }

    printMap(dataMap);

    return 0;
}
