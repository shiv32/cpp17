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
#include <algorithm>
#include <functional>

class myIsDigit
{
public:
    bool operator()(char c) const { return ::isdigit(c) != 0; }
};

bool isNumber(std::string_view str)
{
    auto endIter = end(str);
    auto it = std::find_if(begin(str), endIter, std::not_fn(myIsDigit()));
    return (it == endIter);
}

bool isNumber2(std::string_view str)
{
    //C++11
    class myIsDigit
    {
    public:
        bool operator()(char c) const { return ::isdigit(c) != 0; }
    };

    auto endIter = end(str);
    auto it = std::find_if(begin(str), endIter, std::not_fn(myIsDigit()));
    return (it == endIter);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::cout << isNumber("shiv") << std::endl;
    // std::cout << isNumber("123") << std::endl;
    // std::cout << isNumber("12k") << std::endl;

    std::cout << isNumber2("shiv") << std::endl;
    std::cout << isNumber2("123") << std::endl;
    std::cout << isNumber2("12k") << std::endl;

    return 0;
}