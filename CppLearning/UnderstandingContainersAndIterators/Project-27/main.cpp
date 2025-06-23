/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The pair Utility Class
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <utility>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Two-argument constructor and default constructor
    std::pair<std::string, int> myPair("hello", 5);
    std::pair<std::string, int> myOtherPair;

    // Can assign directly to first and second
    myOtherPair.first = "hello";
    myOtherPair.second = 6;

    // Copy constructor
    std::pair<std::string, int> myThirdPair(myOtherPair);

    // operator<
    if (myPair < myOtherPair)
    {
        std::cout << "myPair is less than myOtherPair" << std::endl;
    }
    else
    {
        std::cout << "myPair is greater than or equal to myOtherPair" << std::endl;
    }

    // operator==
    if (myOtherPair == myThirdPair)
    {
        std::cout << "myOtherPair is equal to myThirdPair" << std::endl;
    }
    else
    {
        std::cout << "myOtherPair is not equal to myThirdPair" << std::endl;
    }

    //------------------------------------------------------------------
    std::pair<int, double> aPair = std::make_pair(5, 10.10);

    auto aSecondPair = std::make_pair(5, 10.10);

    auto aThirdPair = std::pair(5, 10.10); // C++17
    //------------------------------------------------------------------

    //----------------------------------------------------
    std::pair<std::string, int> myPair2("hello", 5);

    auto [theString, theInt] = myPair2; // Decompose using structured bindings, C++17

    std::cout << "theString: " << theString << std::endl;
    std::cout << "theInt: " << theInt << std::endl;
    //----------------------------------------------------

    return 0;
}