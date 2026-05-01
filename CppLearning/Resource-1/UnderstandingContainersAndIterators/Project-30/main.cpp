/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map operator[]
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

void func(const std::map<int, int> &m)
{
    //variable m is a const reference to a map, and operator[] is not marked as const.
    //use the find() method.
    //std::cout << m[1] << std::endl; // Error
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::map<int, Data> dataMap;
    
    dataMap[1] = Data(4);
    printMap(dataMap);
    
    dataMap[1] = Data(6); // Replaces the element with key 1
    printMap(dataMap);
    
    return 0;
}
