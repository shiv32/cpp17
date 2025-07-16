/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map Iterators
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
    for (const auto &pair : dataMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second.getValue() <<
                  std::endl;
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

    std::cout << "iterate : " << std::endl;
    //iterate through the map
    for (auto iter = cbegin(dataMap); iter != cend(dataMap); ++iter)
    {
        std::cout << iter->second.getValue() << std::endl;
        //or
        std::cout << (*iter).second.getValue() << std::endl;
    }

    std::cout << "range-based for loop : " << std::endl;
    //range-based for loop
    for (const auto& p : dataMap)
    {
        std::cout << p.second.getValue() << std::endl;
    }

    std::cout << "structured bindings : " << std::endl;
    // combination of a range-based for loop and C++17 structured bindings
    for (const auto& [key, data] : dataMap)
    {
        std::cout << data.getValue() << std::endl;
    }
    
    return 0;
}
