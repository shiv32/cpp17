/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief map Nodes
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

void printMap(const std::map<int, Data> &dataMap, std::string_view msg = "")
{
    std::cout << msg << std::endl;

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

void printMap(const std::map<int, int> map, std::string_view msg = "")
{
    std::cout << msg << std::endl;

    for (const auto &[key, value] : map)
    {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::map<int, Data> dataMap;

    dataMap[1] = Data(4);
    printMap(dataMap, "before dataMap: ");

    std::map<int, Data> dataMap2;

    // auto extractedNode = dataMap.extract(1);
    // dataMap2.insert(std::move(extractedNode));
    // or
    dataMap2.insert(dataMap.extract(1));

    printMap(dataMap, "after dataMap: ");
    printMap(dataMap2, "dataMap2: ");

    std::map<int, int> src = {{1, 11}, {2, 22}};
    printMap(src, "before src: ");

    std::map<int, int> dst = {{2, 22}, {3, 33}, {4, 44}, {5, 55}};
    printMap(dst, "before dst: ");
    dst.merge(src);

    printMap(src, "after src: ");
    printMap(dst, "after dst: ");

    return 0;
}
