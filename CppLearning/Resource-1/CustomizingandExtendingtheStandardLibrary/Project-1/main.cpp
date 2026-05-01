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
#include <vector>
#include <numeric>  //iota
#include <iterator> //ostream_iterator

namespace osi
{
    void example1()
    {
        std::vector<int> myVector(10);
        std::iota(begin(myVector), end(myVector), 1); // Fill vector with 1,2,3...10

        // Print the contents of the vector.
        // std::copy(cbegin(myVector), cend(myVector), std::ostream_iterator<int>(std::cout, " "));
        std::copy(cbegin(myVector), cend(myVector), std::ostream_iterator<int>(std::cout, ", "));

        std::cout << std::endl;
    }
}

namespace isi
{
    void example1()
    {
        std::cout << "Enter numbers separated by white space." << std::endl;
        // std::cout << "Press Ctrl+Z followed by Enter to stop." << std::endl; //window
        std::cout << "Press Enter followed by Ctrl+D" << std::endl; // Linux

        std::istream_iterator<int> numbersIter(std::cin);
        std::istream_iterator<int> endIter;

        int sum = accumulate(numbersIter, endIter, 0);

        std::cout << "Sum: " << sum << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //osi::example1();
    isi::example1();

    return 0;
}