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

class Mixin1
{
public:
    Mixin1(int i) : mValue(i) {}
    virtual void Mixin1Func() { std::cout << "Mixin1: " << mValue << std::endl; }

private:
    int mValue;
};

class Mixin2
{
public:
    Mixin2(int i) : mValue(i) {}
    virtual void Mixin2Func() { std::cout << "Mixin2: " << mValue << std::endl; }

private:
    int mValue;
};

template <typename... Mixins>
class MyClass : public Mixins...
{
public:
    MyClass(const Mixins &...mixins) : Mixins(mixins)... {}
    virtual ~MyClass() = default;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MyClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
    a.Mixin1Func();
    a.Mixin2Func();

    MyClass<Mixin1> b(Mixin1(33));
    b.Mixin1Func();
    // b.Mixin2Func(); // Error: does not compile.

    MyClass<> c;
    // c.Mixin1Func(); // Error: does not compile.
    // c.Mixin2Func(); // Error: does not compile.

    return 0;
}