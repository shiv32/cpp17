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
#include <algorithm> // for std::find

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------(initialize a vector)----------------------
    // // Declares vector of size 0
    // std::vector<int> vec;

    // std::cout << "vec :";
    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Declares vector of size 5 with provided elements
    // std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // std::cout << "vec2 :";
    // for (auto i : vec2)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Declares vector of size 10
    // std::vector<int> vec3(10);

    // std::cout << "vec3 :";
    // for (auto i : vec3)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Declares vector of size 10 with each element's value = 5
    // std::vector<int> vec4(10, 5);

    // std::cout << "vec4 :";
    // for (auto i : vec4)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    //-------------------(vector insertion functions)-----------------------------------------

    // std::vector<int> vec = {1, 2, 3, 4, 5};

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // generic insert function can be used to insert an element at the front
    // vec.insert(vec.begin(), 0);

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;
    //---------------------------------------------------
    // // Empty vector {}
    // std::vector<int> vec;

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Vector has one element {1}
    // vec.push_back(1);

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Vector has 2 elements {1, 2}
    // vec.push_back(2);

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Vector has 3 elements {0, 1, 2}
    // vec.insert(vec.begin(), 0);

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // // Vector has 4 elements {0, 4, 1, 2}
    // vec.insert(std::find(vec.begin(), vec.end(), 1), 4);

    // for (auto i : vec)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    //----------------(removing elements from a vector)----------------------

    // a vector with 10 elements
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // Vector has now 9 elements {0, 1, 2, 3, 4, 5, 6, 7, 8}
    vec.pop_back();

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // vector has now 8 elements {1, 2, 3, 4, 5, 6, 7, 8}
    vec.erase(vec.begin());

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // Now, vector has 5 elements {1, 5, 6, 7, 8}
    vec.erase(vec.begin() + 1, vec.begin() + 4);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}