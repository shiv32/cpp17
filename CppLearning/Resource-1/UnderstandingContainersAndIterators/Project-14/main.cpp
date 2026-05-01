/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Size and Capacity
 *        Directly Accessing the Data
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------------(Size and Capacity)---------------------
    std::vector<int> vec{1, 2, 3};

    std::cout << "size : " << size(vec) << std::endl;
    std::cout << "is empty : " << empty(vec) << std::endl;
    std::cout << "capacity : " << vec.capacity() << std::endl;

    //----------------(Directly Accessing the Data)-----------------------
    int *data1 = vec.data();
    int *data2 = data(vec);

    std::cout << "data1 address : " << data1 << std::endl;
    std::cout << "data2 address : " << data2 << std::endl;

    std::cout << "data1 data at index 0 : " << *data1 << std::endl;
    std::cout << "data2 data at index 0  : " << *data2 << std::endl;

    std::cout << "data1 data at index 1 : " << *(data1 + 1) << std::endl;
    std::cout << "data2 data at index 1  : " << *(data2 + 1) << std::endl;

    return 0;
}