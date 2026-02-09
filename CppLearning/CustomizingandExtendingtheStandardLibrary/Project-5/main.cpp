/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "hash_map.hpp"

using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    hm::hash_map<int, int> myHash;
    myHash.insert(make_pair(4, 40));
    myHash.insert(make_pair(6, 60));

    // x will have type hash_map<int, int>::value_type*
    auto x = myHash.find(4);

    if (x != nullptr)
    {
        cout << "4 maps to " << x->second << endl;
    }
    else
    {
        cout << "cannot find 4 in map" << endl;
    }

    myHash.erase(4);

    auto x2 = myHash.find(4);

    if (x2 != nullptr)
    {
        cout << "4 maps to " << x2->second << endl;
    }
    else
    {
        cout << "cannot find 4 in map" << endl;
    }

    myHash[4] = 35;
    myHash[4] = 60;

    auto x3 = myHash.find(4);

    if (x3 != nullptr)
    {
        cout << "4 maps to " << x3->second << endl;
    }
    else
    {
        cout << "cannot find 4 in map" << endl;
    }

    // Test std::swap().
    hm::hash_map<int, int> other(std::equal_to<>(), 11);
    swap(other, myHash);

    // Test copy construction and copy assignment.
    hm::hash_map<int, int> myHash2(other);
    hm::hash_map<int, int> myHash3;
    myHash3 = myHash2;

    // Test move construction and move assignment.
    hm::hash_map<int, int> myHash4(std::move(myHash3));
    hm::hash_map<int, int> myHash5;
    myHash5 = std::move(myHash4);

    return 0;
}