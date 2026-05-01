/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map Looking Up Elements
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
    int getValue() const
    {
        return mValue;
    }
    void setValue(int value)
    {
        mValue = value;
    }

private:
    int mValue;
};

void printMap(const std::map<int, Data> &dataMap)
{
    // Print keys and values
    // for (const auto &pair : dataMap)
    // {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second.getValue() << std::endl;
    // }

    // combination of a range-based for loop and C++17 structured bindings
    for (const auto &[key, data] : dataMap)
    {
        std::cout << "Key: " << key << ", Value: " << data.getValue() << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::map<int, Data> dataMap;

    dataMap[1] = Data(4);
    printMap(dataMap);

    dataMap[1] = Data(6); // Replaces the element with key 1
    printMap(dataMap);

    // If you already know that an element with a given key is in a map,
    dataMap[1].setValue(100);
    printMap(dataMap);

    // if you don’t know whether the element exists
    auto it = dataMap.find(1);

    if (it != end(dataMap))
    {
        it->second.setValue(200);
    }
    printMap(dataMap);

    // If you want to check if a key exists in the map
    // Using count() method
    dataMap.count(1) ? std::cout << "Key 1 exists in the map." << std::endl
                     : std::cout << "Key 1 does not exist in the map." << std::endl;

    return 0;
}
