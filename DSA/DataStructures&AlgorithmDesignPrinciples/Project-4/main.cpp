/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  std::vector – Variable Length Array
 * @version 0.1
 * @date 2024-09-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------(initialize a vector)----------------------
    // Declares vector of size 0
    std::vector<int> vec;

    std::cout << "vec :";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // Declares vector of size 5 with provided elements
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    std::cout << "vec2 :";
    for (auto i : vec2)
        std::cout << i << " ";
    std::cout << std::endl;

    // Declares vector of size 10
    std::vector<int> vec3(10);

    std::cout << "vec3 :";
    for (auto i : vec3)
        std::cout << i << " ";
    std::cout << std::endl;

    // Declares vector of size 10 with each element's value = 5
    std::vector<int> vec4(10, 5);

    std::cout << "vec4 :";
    for (auto i : vec4)
        std::cout << i << " ";
    std::cout << std::endl;
}