/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief STREAM ITERATORS
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <numeric>  // For std::iota
#include <iterator> // Required for std::ostream_iterator

int add(int a, int b) { return a + b; }

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Output Stream Iterator
    std::vector<int> myVector(10);
    std::iota(begin(myVector), end(myVector), 1); // Fill vector with 1,2,3...10
    // Print the contents of the vector.
    copy(cbegin(myVector), cend(myVector), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Input Stream Iterator
    std::cout << "Enter numbers separated by white space." << std::endl;
    std::cout << "Press Enter followed by Ctrl+D to stop." << std::endl;
    std::istream_iterator<int> numbersIter(std::cin);
    std::istream_iterator<int> endIter;
    int sum = accumulate(numbersIter, endIter, 0);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}