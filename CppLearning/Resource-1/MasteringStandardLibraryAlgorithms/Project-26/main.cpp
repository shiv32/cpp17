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

namespace pa
{
    void example1()
    {
        std::vector<int> vec1, vecOdd, vecEven;

        populateContainer(vec1);

        vecOdd.resize(size(vec1));
        vecEven.resize(size(vec1));

        auto pairIters = partition_copy(cbegin(vec1), cend(vec1), begin(vecEven), begin(vecOdd),

                                        [](int i)
                                        { return i % 2 == 0; }

        );

        vecEven.erase(pairIters.first, end(vecEven));
        vecOdd.erase(pairIters.second, end(vecOdd));

        std::cout << "Even numbers: ";
        for (const auto &i : vecEven)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl<< "Odd numbers: ";
        
        for (const auto &i : vecOdd)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    // all even numbers followed by all odd numbers.
    void example2()
    {
        std::vector<int> vec;

        populateContainer(vec);

        partition(begin(vec), end(vec), [](int i){ return i % 2 == 0; });

        std::cout << "Partitioned result: ";

        for (const auto &i : vec)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }
}

namespace sa
{
    void example1()
    {
        std::vector<int> vec;
        populateContainer(vec);

        sort(begin(vec), end(vec), std::greater<>());

        for (const auto &i : vec)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // pa::example1();
    //pa::example2();

    sa::example1();

    return 0;
}