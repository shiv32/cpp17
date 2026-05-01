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

namespace sa
{
    // The list of elements to be searched
    // std::vector<int> myVector = {5, 6, 9, 8, 8, 3};
    std::vector<int> myVector = {8, 3, 5, 6, 9, 8, 8, 3};
    // std::vector<int> myVector = {8, 3, 5, 6, 9, 8, 3};
    
    auto beginIter = cbegin(myVector);
    auto endIter = cend(myVector);

    void example1()
    {
        // Find the first element that does not satisfy the given lambda expression
        auto it = find_if_not(beginIter, endIter, [](int i)
                              { return i < 8; });
        if (it != endIter)
        {
            std::cout << "First element not < 8 is " << *it << std::endl;
        }
    }

    void example2()
    {
        // Find the first pair of matching consecutive elements
        auto it = adjacent_find(beginIter, endIter);

        if (it != endIter)
        {
            std::cout << "Found two consecutive equal elements with value " << *it << std::endl;
        }
    }

    void example3()
    {
        // Find the first of two values
        std::vector<int> targets = {8, 9};
        auto it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));

        if (it != endIter)
        {
            std::cout << "Found one of 8 or 9: " << *it << std::endl;
        }
    }

    void example4()
    {
        // Find the first subsequence
        std::vector<int> sub = {8, 3};
        auto it = search(beginIter, endIter, cbegin(sub), cend(sub));

        if (it != endIter)
        {
            std::cout << "Found subsequence {8,3}" << std::endl;
        }
        else
        {
            std::cout << "Unable to find subsequence {8,3}" << std::endl;
        }

        // Find the last subsequence (which is the same as the first in this example)
        auto it2 = find_end(beginIter, endIter, cbegin(sub), cend(sub));

        if (it != it2)
        {
            std::cout << "Error: search and find_end found different subsequences "
                      << "even though there is only one match." << std::endl;
        }
    }

    void example5()
    {
        // Find the first subsequence of two consecutive 8s
        auto it = search_n(beginIter, endIter, 2, 8);

        if (it != endIter)
        {
            std::cout << "Found two consecutive 8s" << std::endl;
        }
        else
        {
            std::cout << "Unable to find two consecutive 8s" << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    sa::example1();
    sa::example2();
    sa::example3();
    sa::example4();
    sa::example5();

    return 0;
}