/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

namespace fv1
{
    template <unsigned char f>
    class Factorial
    {
    public:
        static const unsigned long long val = (f * Factorial<f - 1>::val);
    };

    template <>
    class Factorial<0>
    {
    public:
        static const unsigned long long val = 1;
    };
}

namespace fv2
{
    constexpr unsigned long long Factorial(unsigned char f)
    {
        if (f == 0)
        {
            return 1;
        }
        else
        {
            return f * Factorial(f - 1);
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << fv1::Factorial<6>::val << std::endl; //value is calculated at compile time

    constexpr auto f1 = fv2::Factorial(6); //value is calculated at compile time
    std::cout << f1 << std::endl;

    auto f2 = fv2::Factorial(6); // calculation happens at run time
    std::cout << f2 << std::endl;

    return 0;
}