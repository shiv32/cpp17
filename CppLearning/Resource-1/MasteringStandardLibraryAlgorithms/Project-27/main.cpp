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

namespace bsa
{
    void example1()
    {
        std::vector<int> vec;
        populateContainer(vec);

        // Sort the container
        sort(begin(vec), end(vec));

        std::cout << "Sorted vector: ";
        for (const auto &i : vec)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        while (true)
        {
            int num;
            std::cout << "Enter a number to insert (0 to quit): ";
            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            // It is often used to find at which position in a sorted vector a new value should be inserted,
            // so that the vector remains sorted.
            auto iter = lower_bound(begin(vec), end(vec), num);
            vec.insert(iter, num);

            std::cout << "New vector: ";
            for (const auto &i : vec)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

    void example2()
    {
        std::vector<int> vec;
        populateContainer(vec);

        // Sort the container
        sort(begin(vec), end(vec));

        while (true)
        {
            int num;
            std::cout << "Enter a number to find (0 to quit): ";
            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            // The binary_search() algorithm finds a matching element in logarithmic time instead of linear time.
            if (binary_search(cbegin(vec), cend(vec), num))
            {
                std::cout << "That number is in the vector." << std::endl;
            }
            else
            {
                std::cout << "That number is not in the vector." << std::endl;
            }
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // bsa::example1();
    bsa::example2();

    return 0;
}