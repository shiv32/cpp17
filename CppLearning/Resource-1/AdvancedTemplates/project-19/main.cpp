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

class IsDoable
{
public:
    void doit() const { std::cout << "IsDoable::doit()" << std::endl; }
};

class Derived : public IsDoable
{
};

namespace example1
{
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IsDoable, T>, void> call_doit(const T &t)
    {
        t.doit();
    }

    template <typename T>
    std::enable_if_t<!std::is_base_of_v<IsDoable, T>, void> call_doit(const T &)
    {
        std::cout << "Cannot call doit()!" << std::endl;
    }
}

namespace example2
{
    // using C++17 constexpr if

    template <typename T>
    // void call_doit(const T &[[maybe_unused]] t)
    void call_doit([[maybe_unused]] const T &t)
    {
        if constexpr (std::is_base_of_v<IsDoable, T>)
        {
            t.doit();
        }
        else
        {
            std::cout << "Cannot call doit()!" << std::endl;
        }
    }
}

namespace example3
{
    /*
        Instead of using the is_base_of type trait,
        you can also use the new C++17 is_invocable trait
    */

    template <typename T>
    // void call_doit(const T &[[maybe_unused]] t)
    void call_doit([[maybe_unused]] const T &t)
    {
        if constexpr (std::is_invocable_v<decltype(&IsDoable::doit), T>)
        {
            t.doit();
        }
        else
        {
            std::cout << "Cannot call doit()!" << std::endl;
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Derived d;

    example1::call_doit(d);
    example1::call_doit(123);

    example2::call_doit(d);
    example2::call_doit(123);

    example3::call_doit(d);
    example3::call_doit(123);

    return 0;
}