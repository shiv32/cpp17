/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

template <typename Tuple, size_t... Indices>
void tuple_print_helper(const Tuple &t, std::index_sequence<Indices...>)
{
    ((std::cout << std::get<Indices>(t) << std::endl), ...); // unary right fold expression
}

/*
unary right fold expression

(((cout << get<0>(t) << endl),((cout << get<1>(t) << endl),((cout << get<2>(t) << endl),(cout << get<3>(t) << endl)))));

( ((0), ((1), ((2),(3)) ) ) );
 
*/

template <typename... Args>
void tuple_print(const std::tuple<Args...> &t)
{
    tuple_print_helper(t, std::index_sequence_for<Args...>());
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto t1 = std::make_tuple(167, "Testing", false, 2.3);
    tuple_print(t1);

    return 0;
}