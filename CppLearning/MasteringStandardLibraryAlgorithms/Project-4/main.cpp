/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto basicLambda = []{ std::cout << "Hello from Lambda" << std::endl; };
    basicLambda();

    auto parametersLambda = [](int value){ std::cout << "The value is " << value << std::endl; };
    parametersLambda(42);

    auto returningLambda = [](int a, int b) -> int { return a + b; }; //trailing return type
    int sum = returningLambda(11, 22);
    std::cout << "sum " << sum << std::endl;

    auto returningLambda2 = [](int a, int b){ return a + b; };
    sum = returningLambda2(11, 22);
    std::cout << "sum " << sum << std::endl;

    double data = 1.23;
    auto capturingLambda = [data]{ std::cout << "Data = " << data << std::endl; };
    capturingLambda();

    const double data2 = 1.23;
    auto capturingLambda2 = [data2]{ std::cout << "Data = " << data2 << std::endl; };
    capturingLambda2();

    auto capturingLambda3 = [data] () mutable { data *= 2; std::cout << "Data = " << data << std::endl; }; //mutable
    capturingLambda3();

    auto capturingLambda4 = [&data]{ data *= 2; };
    capturingLambda4();
    std::cout << "&Data = " << data << std::endl;

    return 0;
}