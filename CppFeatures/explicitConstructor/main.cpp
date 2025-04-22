/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief explicit Constructor
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

class MyClass
{
public:
    // MyClass(int x)
    // {
    //     std::cout << "MyClass constructed with x = " << x << "\n";
    // }

    explicit MyClass(int x)
    {
        std::cout << "MyClass constructed with x = " << x << "\n";
    }
};

void doSomething(MyClass obj)
{
    std::cout << "Inside doSomething()\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MyClass a(42); // ✅ OK: direct initialization, work in both cases with/without explicit

    // doSomething(42); // ❌ ERROR: implicit conversion is not allowed due to `explicit`

    // doSomething(MyClass(42)); // ✅ OK: explicit conversion

    return 0;
}