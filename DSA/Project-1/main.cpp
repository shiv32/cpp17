/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ModernCpp
 * @version 0.1
 * @date 2024-08-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <initializer_list>

void Print(std::initializer_list<int> list)
{

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // uniform initialization
    int i1 = 0;
    int i2{0};
    int i3{};   // default value 0
    int *ptr{}; // default value NULL
    int arr[5] = {1, 2, 3};

    std::initializer_list<int> list{1,2,3,4};
}