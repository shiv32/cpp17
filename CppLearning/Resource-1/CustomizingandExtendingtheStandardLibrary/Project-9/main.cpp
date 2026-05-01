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
#include <map>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    hm::hash_map<string, int> myHash;

    myHash.insert(make_pair("KeyOne", 100));
    myHash.insert(make_pair("KeyTwo", 200));
    myHash.insert(make_pair("KeyThree", 300));

    for (auto it = myHash.cbegin(); it != myHash.cend(); ++it)
    {
        // Use both -> and * to test the operations.
        cout << it->first << " maps to " << (*it).second << endl;
    }

    cout << "----------------------" << endl;

    // Print elements using a range-based for loop
    for (auto &p : myHash)
    {
        cout << p.first << " maps to " << p.second << endl;
    }

    cout << "----------------------" << endl;

    // Print elements using a range-based for loop and C++17 structured bindings
    for (auto &[key, value] : myHash)
    {
        cout << key << " maps to " << value << endl;
    }

    cout << "----------------------" << endl;

    // Create an std::map with all the elements in the hash_map.
    map<string, int> myMap(cbegin(myHash), cend(myHash));
    for (auto &p : myMap)
    {
        cout << p.first << " maps to " << p.second << endl;
    }

    cout << "----------------------" << endl;

    return EXIT_SUCCESS;
}