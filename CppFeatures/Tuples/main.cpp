/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Tuples
 *

 *
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <tuple> // Required for std::tuple

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
        The std::pair class, defined in <utility>, can store exactly two values, each with a specific type.
    */

    std::pair<int, std::string> p1(16, "Hello World");

    std::pair<bool, float> p2(true, 0.123f);

    std::cout << "p1 = (" << p1.first << ", " << p1.second << ")" << std::endl;

    std::cout << "p2 = (" << p2.first << ", " << p2.second << ")" << std::endl;

    /*
        An std::tuple, defined in <tuple>, is a generalization of a pair.
        It allows you to store any number of values, each with its own specific type.
    */

    using MyTuple = std::tuple<int, std::string, bool>;

    MyTuple t1(16, "Test", true);
    // MyTuple t1{16, "Test", true};

    std::cout << "t1 = (" << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << ")" << std::endl;

    return 0;
}