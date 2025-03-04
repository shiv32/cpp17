/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Reverse Iterators
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // Required for std::ostream_iterator

// Function template to populate a container of ints.
// The container must support push_back().
template <typename Container>
void populateContainer(Container &cont)
{
    int num;

    while (true)
    {
        std::cout << "Enter a number (0 to quit): ";

        std::cin >> num;

        if (num == 0)
        {
            break;
        }
        cont.push_back(num);
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<int> myVector;

    populateContainer(myVector);

    int num;
    std::cout << "Enter a number to find: ";
    std::cin >> num;

    auto it1 = std::find(begin(myVector), end(myVector), num);
    auto it2 = std::find(rbegin(myVector), rend(myVector), num);

    if (it1 != end(myVector))
    {
        std::cout << "Found " << num << " at position " << it1 - begin(myVector)
                  << " going forward." << std::endl;
        std::cout << "Found " << num << " at position "
                  << it2.base() - 1 - begin(myVector) << " going backward." << std::endl;
    }
    else
    {
        std::cout << "Failed to find " << num << std::endl;
    }

    return 0;
}