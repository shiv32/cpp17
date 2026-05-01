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
#include <algorithm>
#include <functional>
#include <list>

namespace ca
{
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

    void example1()
    {
        std::vector<int> myVector;
        std::list<int> myList;

        std::cout << "Populate the vector:" << std::endl;
        populateContainer(myVector);

        std::cout << "Populate the list:" << std::endl;
        populateContainer(myList);

        // Compare the two containers
        if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList)))
        {
            std::cout << "The two containers have equal elements" << std::endl;
        }
        else
        {
            // If the containers were not equal, find out why not
            auto miss = mismatch(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList));

            std::cout << "The following initial elements are the same in " << "the vector and the list:" << std::endl;

            for (auto i = cbegin(myVector); i != miss.first; ++i)
            {
                std::cout << *i << '\t';
            }

            std::cout << std::endl;
        }

        // Now order them.
        if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList)))
        {
            std::cout << "The vector is lexicographically first." << std::endl;
        }
        else
        {
            std::cout << "The list is lexicographically first." << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ca::example1();

    return 0;
}