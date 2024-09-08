/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  A General-Purpose and Fast Data Storage Container Builder
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "Build_array.hpp"
#include <memory>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto ba = std::make_unique<Build_array>();

    auto data = ba->build_array(1, 0u, 'a', 3.2f, false);

    for (auto i : data)
        std::cout << i << " ";

    std::cout << std::endl;

    // auto data2 = ba->build_array(1, "Packt", 2.0);  //error
    auto data2 = ba->build_array(1, 'P', 2.0); // working
}