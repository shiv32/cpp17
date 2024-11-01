/*
More on Template Parameter Deduction

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "mytemplate.hpp"

int main()
{
    // case 1
    auto result = add<long long, int, int>(1, 2);

    std::cout << "result : " << result << std::endl;

    result = add<long long>(1, 2);

    std::cout << "result : " << result << std::endl;

    // case 2
    result = add2<int, long long>(1, 5);

    std::cout << "result : " << result << std::endl;

    // case 3
    result = add3(1, 6);

    std::cout << "result : " << result << std::endl;

    return 0;
}