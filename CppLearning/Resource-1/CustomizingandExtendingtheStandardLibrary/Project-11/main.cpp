#include <iostream>
#include "hash_map.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    hm::hash_map<string, int> myHash{{"KeyOne", 100}, {"KeyTwo", 200}, {"KeyThree", 300}};
    // hm::hash_map<string, int> myHash{};
    // myHash = {{"KeyOne", 100}, {"KeyTwo", 200}, {"KeyThree", 300}};
    myHash.insert({{"KeyFour", 400}, {"KeyFive", 500}});

    // Print elements using a range-based for loop and C++17 structured bindings
    for (auto &[key, value] : myHash)
    {
        cout << key << " maps to " << value << endl;
    }

    return EXIT_SUCCESS;
}