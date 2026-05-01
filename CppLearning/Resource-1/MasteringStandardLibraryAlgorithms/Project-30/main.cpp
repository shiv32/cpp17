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
#include <execution>

template <typename container>
void printContainer(container cnt)
{
    for (const auto item : cnt)
    {
        std::cout << item << ", ";
    }

    std::cout << std::endl;
}

namespace pa
{
    void example1()
    {
        std::vector<int> myVector{7, 2, 8, 3};

        printContainer(myVector);

        // The algorithm is allowed to parallelize its execution.
        std::sort(std::execution::par, begin(myVector), end(myVector));

        // The algorithm is not allowed to parallelize its execution.
        //   std::sort(std::execution::seq, begin(myVector), end(myVector));

        /*
        The algorithm is allowed to parallelize and vectorize its execution.
        It’s also allowed to migrate its execution across threads.
        */
        // std::sort(std::execution::par_unseq, begin(myVector), end(myVector));

        printContainer(myVector);
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    pa::example1();

    return 0;
}