/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Compile-Time Assert
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    constexpr unsigned int version = 3U;
    //constexpr unsigned int version = 1U;

    // Print error message if version is less than 2.
    // static_assert(version >= 2U, "Version is too low!");

    // Print default error message if version is not 3.
    static_assert(version == 3U);

    std::cout<<"Version : "<<version<<std::endl;

    return 0;
}