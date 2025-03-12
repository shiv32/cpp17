/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Iterator Traits
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <iterator>

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
    // typename std::iterator_traits<IteratorType>::value_type temp;
    // temp = *it;
    // or
    auto temp = *it;
    std::cout << temp << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<int> v{5};
    iteratorTraitsTest(cbegin(v));

    return 0;
}