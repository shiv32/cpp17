/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief std::function
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <functional>

void hello()
{
    std::cout << "Hello from function!\n";
}

void doSomething(const std::function<void(int)> &callback)
{
    callback(42);
}

struct Foo
{
    void print(int x)
    {
        std::cout << "Value: " << x << '\n';
    }
};

int add(int a, int b) { return a + b; }

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Basic Syntax
    std::function<void()> func = hello;
    func(); // Calls hello

    //----------------- Common Use Cases ------------------------------------

    // 1. Storing Lambdas
    std::function<int(int, int)> add = [](int a, int b)
    {
        return a + b;
    };

    std::cout << add(3, 4) << std::endl; // 7

    // 2. Passing Callbacks
    doSomething([](int x)
                { std::cout << "Callback got: " << x << '\n'; });

    // 3. Storing Member Functions
    Foo f;
    std::function<void(Foo &, int)> func2 = &Foo::print;
    func2(f, 10);

    // 4. Using std::bind
    auto add5 = std::bind(add, 5, std::placeholders::_1);
    std::cout << add5(3) << std::endl; // Outputs 8

    return 0;
}