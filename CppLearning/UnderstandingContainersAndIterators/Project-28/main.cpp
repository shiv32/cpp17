/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Constructing maps
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

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::map<int, Data> dataMap;

    Data d1(345), d2(678), d3(143);

    dataMap[0] = d1;
    dataMap[1] = d2;
    dataMap[2] = d3;

    // Print keys and values
    for (const auto &pair : dataMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second.getValue() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    // uniform initialization:
    std::map<std::string, int> contactMap = {
        {"Marc G.", 123},
        {"Warren B.", 456},
        {"Peter V.W.", 789}};

    // Print keys and values
    for (const auto &pair : contactMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
