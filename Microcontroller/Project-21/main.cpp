/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief A Tutorial for Real-Time C++ MCU : tuple
 * @version 0.1
 * @date 2025-03-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <tuple>

// typedef std::tuple<float, char, int> tuple_type;
using tuple_type = std::tuple<float, char, int>;

tuple_type t = std::make_tuple(1.24F, char('b'), 321);

void do_something()
{
    // Make a tuple of a float, char and an int.
    tuple_type t(1.23F, char('a'), 123);

    // Get element number 1 of the tuple (’a’).
    char c = std::get<1>(t);
    std::cout << "c : " << c << std::endl;

    // Get element number 2 of the tuple (123).
    int n = std::get<2>(t);
    std::cout << "n : " << n << std::endl;

    // Use the type member of tuple_element to obtain
    // the float value of the zero’th tuple element.
    std::tuple_element<0, tuple_type>::type val = std::get<0>(t);
    std::cout << "val : " << val << std::endl;

    // Get the size of the tuple.
    int size = std::tuple_size<tuple_type>::value;
    std::cout << "size : " << size << std::endl;
}

void do_something2()
{
    std::tuple<int, std::string> t1(123, "identical");
    std::tuple<int, std::string> t2 = t1;
    std::tuple<int, std::string> t3(t1);

    bool result;
    result = (t1 == t2);
    // true
    std::cout << "t1 == t2 : " << result << std::endl;

    result = (t1 == t3);
    // true
    std::cout << "t1 == t3 : " << result << std::endl;

    std::get<0>(t2) += 1; // 123 -> 124

    std::cout << "t2 : " << std::get<0>(t2) << std::endl;

    result = (t2 > t1);
    // true
    std::cout << "t2 > t1 : " << result << std::endl;

    // Transform identical -> xdentical
    std::get<1>(t3).at(0U) = 'x';
    std::cout << "t3 : " << std::get<1>(t3) << std::endl;

    result = (t3 > t1);
    // true
    std::cout << "t3 > t1 : " << result << std::endl;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // do_something();

    // std::tuple_element<0, tuple_type>::type val = std::get<0>(t);
    // std::cout << "val : " << val << std::endl;

    do_something2();

    return 0;
}
