/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Insert Iterators
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

    std::vector<int> vectorOne, vectorTwo;

    populateContainer(vectorOne);

    std::back_insert_iterator<std::vector<int>> inserter(vectorTwo);

    copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
            [](int i)
            { return i != 100; });

    copy(cbegin(vectorTwo), cend(vectorTwo), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    return 0;
}