/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 *  g++ main.cpp -o test_boost -lboost_system && ./test_boost && rm test_boost
 *
 * @version 0.1
 * @date 2024-12-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <boost/version.hpp>
#include <boost/asio.hpp>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    boost::asio::io_service io;

    std::cout << "Boost version: " << BOOST_VERSION / 100000 << "."
              << BOOST_VERSION / 100 % 1000 << "."
              << BOOST_VERSION % 100 << std::endl;

    std::cout << "Boost.Asio works!" << std::endl;
    return 0;
}
