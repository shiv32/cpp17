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

namespace transform
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
        populateContainer(myVector);

        std::cout << "The vector contains:" << std::endl;

        for (const auto &i : myVector)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;

        std::transform(begin(myVector), end(myVector), begin(myVector), [](int i)
                       { return i + 100; });

        std::cout << "The vector contains:" << std::endl;

        for (const auto &i : myVector)
        {
            std::cout << i << " ";
        }
    }

    void example2()
    {
        std::vector<int> vec1, vec2;

        std::cout << "Vector1:" << std::endl;
        populateContainer(vec1);

        std::cout << "Vector2:" << std::endl;
        populateContainer(vec2);

        if (vec2.size() < vec1.size())
        {
            std::cout << "Vector2 should be at least the same size as vector1." << std::endl;
            // return 1;
        }

        // Create a lambda to print the contents of a container
        auto printContainer = [](const auto &container)
        {
            for (auto &i : container)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        };

        std::cout << "Vector1: ";
        printContainer(vec1);

        std::cout << "Vector2: ";
        printContainer(vec2);

        std::transform(begin(vec1), end(vec1), begin(vec2), begin(vec1), [](int a, int b){ return a + b; });

        std::cout << "Vector1: ";
        printContainer(vec1);
        
        std::cout << "Vector2: ";
        printContainer(vec2);
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // transform::example1();
    transform::example2();

    return 0;
}