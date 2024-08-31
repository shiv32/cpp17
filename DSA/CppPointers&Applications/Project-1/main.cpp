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

class Test
{
    int m_value{}; // uniform initialization
                   // default value 0

public:
    // Test() : m_value{0} {};  //no need default ctor if we initiliaze m_value in class

    Test() = default;
    Test(int x) : m_value{x} {};
};

void Print(std::initializer_list<int> list)
{
    // std::initializer_list<int>::iterator it = list.begin();
    // or
    // auto it = list.begin();

    // while (it != list.end())
    // {
    //     std::cout << *it << ' ';
    //     ++it;
    // }

    // for(int x: list)                      //copy
    // {
    // std::cout << x << ' ';
    // }

    // for (auto x : list)    //copy
    // {
    //     std::cout << x << ' ';
    // }

    for (const auto &x : list) // reference
    {
        std::cout << x << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // uniform initialization
    int i1 = 0;
    int i2{0};
    int i3{}; // default value 0

    int *ptr{}; // default value NULL

    auto ptr2 = ptr;
    // or
    // auto *ptr2 = ptr;

    int arr[5] = {1, 2, 3};

    std::initializer_list<int> list{1, 2, 3, 4};

    // Print(list);

    Print({1, 2, 3, 4, 5});
}