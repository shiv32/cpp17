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

// fun overload
void handleValue(int value) { std::cout << "Integer: " << value << std::endl; }
void handleValue(double value) { std::cout << "Double: " << value << std::endl; }
void handleValue(std::string_view value) { std::cout << "String: " << value << std::endl; }

template <typename... Tn>
void processValues(const Tn &...args)
{
    (handleValue(args), ...);
}

template <typename... Values>
void printValues(const Values &...values)
{
    ((std::cout << values << std::endl), ...);
}

template <typename T, typename... Values>
double sumValues(const T &init, const Values &...values)
{
    return (init + ... + values);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    processValues(1, 2, 3.56, "test", 1.1f);

    // printValues(1, "test", 2.34);

    // std::cout << sumValues(1, 2, 3.3) << std::endl;
    // std::cout << sumValues(1) << std::endl;

    // std::cout << sumValues() << std::endl; //compile error candidate expects at least 1 argument, 0 provided

    return 0;
}