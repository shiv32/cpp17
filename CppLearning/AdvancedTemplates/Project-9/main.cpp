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

template <typename T>
void numberOfArg(T numOfArgs)
{
    std::cout << "numOfArgs: " << numOfArgs << std::endl;
}

// fun overload -------------------------------
void handleValue(int value)
{
    std::cout << "Integer: " << value << std::endl;
}

void handleValue(double value)
{
    std::cout << "Double: " << value << std::endl;
}

void handleValue(std::string_view value)
{
    std::cout << "String: " << value << std::endl;
}
//--------------------------------------------

void processValues()
{
    /* Nothing to do in this base case.*/
}

template <typename T1, typename... Tn>  // triple dots ... operator, parameter pack
void processValues(T1 arg1, Tn... args) // triple dots ... operator, parameter pack
{
    // int numOfArgs = sizeof...(args);
    // std::cout << "numOfArgs: " << numOfArgs << std::endl;
    numberOfArg(sizeof...(args));

    handleValue(arg1);
    processValues(args...); // triple dots ... operator, parameter pack expansion
}

void processValues2()
{
    /* Nothing to do in this base case.*/
}

/*
 To use non-const references and still allow literal values, you can use forwarding references.
 Uses forwarding references, T&&, and uses std::forward() for perfect forwarding of all parameters.
*/
template <typename T1, typename... Tn>
void processValues2(T1 &&arg1, Tn &&...args)
{
    // int numOfArgs = sizeof...(args);
    // std::cout << "numOfArgs: " << numOfArgs << std::endl;
    numberOfArg(sizeof...(args));

    handleValue(std::forward<T1>(arg1));
    processValues2(std::forward<Tn>(args)...);
}

/*
suppose args is a parameter pack with three arguments, a1, a2, and a3, of three types, A1, A2, and A3.
The expanded call then looks as follows:

processValues(  std::forward<A1>(a1),
                std::forward<A2>(a2),
                std::forward<A3>(a3)
             );
*/

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    processValues(1, 2, 3.56, "test", 1.1f); // the parameters are copied for each recursive call to processValues()
    std::cout << "-------------------------------" << std::endl;
    processValues2(1, 2, 3.56, "test", 1.1f); // Perfect forwarding

    return 0;
}