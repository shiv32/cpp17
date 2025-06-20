/*
Initializer-List Constructors

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "EvenSequence.hpp"

int main()
{
    // EvenSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    EvenSequence p1{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    p1.dump();

    try
    {
        EvenSequence p2 = {1.0, 2.0, 3.0};
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------
    // std::vector container can be initialized with an initializer-list
    std::vector<std::string> myVec = {"String 1", "String 2", "String 3"};

    // or
    /*
    std::vector<std::string> myVec;
    myVec.push_back("String 1");
    myVec.push_back("String 2");
    myVec.push_back("String 3");
     */

    for (const auto &value : myVec)
    {
        std::cout << value << ", ";
    }

    std::cout << std::endl;

    return 0;
}