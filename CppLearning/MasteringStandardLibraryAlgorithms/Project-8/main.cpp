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

namespace binders
{
    void func(int num, std::string_view str)
    {
        std::cout << "func(" << num << ", " << str << ")" << std::endl;
    }

    void example1()
    {
        std::string myString = "abc";
        auto f1 = std::bind(func, std::placeholders::_1, myString);
        f1(16);
    }

    void example2()
    {
        auto f2 = std::bind(func, std::placeholders::_2, std::placeholders::_1);
        f2("Test", 32);
    }

    void increment(int &value) { ++value; }

    void example3()
    {
        int index = 0;
        increment(index);
        std::cout << "index : " << index << std::endl;
    }

    void example4()
    {
        int index = 0;
        auto incr = std::bind(increment, index);
        incr();
        std::cout << "index : " << index << std::endl;
    }

    void example5()
    {
        int index = 0;
        auto incr = std::bind(increment, std::ref(index));
        incr();
        std::cout << "index : " << index << std::endl;
    }

    void overloaded(int num) { std::cout << "int called" << std::endl; }
    void overloaded(float f) { std::cout << "float called" << std::endl; }

    void example6()
    {
        // auto f3 = std::bind(overloaded, std::placeholders::_1); // ERROR
        auto f4 = std::bind((void (*)(float))overloaded, std::placeholders::_1); // OK
        f4(8.5);

        auto f5 = std::bind((void (*)(int))overloaded, std::placeholders::_1); // OK
        f5(8);
    }

    std::vector<int> myVector{2, 5, 600, 8};

    void example7()
    {
        auto endIter = std::end(myVector);
        auto it = find_if(std::begin(myVector), endIter, std::bind(std::greater_equal<>(), std::placeholders::_1, 100));

        if (it == endIter)
        {
            std::cout << "No perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"perfect\" score of " << *it << std::endl;
        }
    }

    void example8()
    {
        auto endIter = std::end(myVector);

        //Of course, in this case, I would recommend the solution using a lambda expression
        auto it = find_if(begin(myVector), endIter, [](int i){ return i >= 100; });

        if (it == endIter)
        {
            std::cout << "No perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"perfect\" score of " << *it << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    binders::example1();
    binders::example2();
    binders::example3();
    binders::example4();
    binders::example5();
    binders::example6();
    binders::example7();
    binders::example8();

    return 0;
}