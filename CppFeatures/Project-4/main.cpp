/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Templates

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

// int sum(int a, int b)
// {
//    return a+b;
// }

// double sum(double a, double b)
// {
//    return a+b;
// }

template <typename T>
T sum(T a, T b)
{
    return a + b;
}

template <typename T, typename T2>
T2 sum2(T a, T b)
{
    return a + b;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int ff;


    // int s = sum(3,8);
    // double s = sum(3.5,8.3);
    // double s = sum<double>(3.5,8.3);

    //double s = sum2(3.5, 8.3); //compilation error
    double s = sum2<double,double>(3.5,8.3);

    std::cout << "sum : " << s << std::endl;

    int (*pfn)(int, int) = sum;

    std::cout << "sum fpn : " << pfn(4,7) << std::endl;

    return 0;
}