/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Tuples
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <tuple> // Required for std::tuple

struct Foo
{
    int mInt;
    std::string mStr;
    bool mBool;
};

class Foo2
{
public:
    Foo2(std::string str, int i) : mStr(str), mInt(i) {}

    std::string getStr()
    {
        return mStr;
    }

    int getInt()
    {
        return mInt;
    }

private:
    std::string mStr;
    int mInt;
};

bool operator<(const Foo &f1, const Foo &f2)
{
    return tie(f1.mInt, f1.mStr, f1.mBool) < tie(f2.mInt, f2.mStr, f2.mBool);
}

int add(int a, int b) { return a + b; }

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
        The std::pair class, defined in <utility>, can store exactly two values, each with a specific type.
    */

    std::pair<int, std::string> p1(16, "Hello World");

    std::pair<bool, float> p2(true, 0.123f);

    std::cout << "p1 = (" << p1.first << ", " << p1.second << ")" << std::endl;

    std::cout << "p2 = (" << p2.first << ", " << p2.second << ")" << std::endl;

    /*
        An std::tuple, defined in <tuple>, is a generalization of a pair.
        It allows you to store any number of values, each with its own specific type.
    */

    using MyTuple = std::tuple<int, std::string, bool>;

    MyTuple t1(16, "Test", true);
    // MyTuple t1{16, "Test", true};

    std::cout << "t1 = (" << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << ")"
              << std::endl;

    auto [i, str, b] = t1; // Structured bindings, introduced in C++17.

    std::cout << "Decomposed: i = "
              << i << ", str = \"" << str << "\", b = " << b << std::endl;

    std::tuple<int, std::string, bool> t2(166, "Test", true);

    int i2 = 0;
    std::string str2;
    bool b2 = false;

    std::cout << "Before: i = " << i2 << ", str = \"" << str2 << "\", b = " << b2 << std::endl;

    tie(i2, str2, b2) = t2;

    std::cout << "After: i = " << i2 << ", str = \"" << str2 << "\", b = " << b2 << std::endl;

    tie(i, std::ignore, b) = t2;

    std::cout << "After ignore: i = " << i << ", b = " << b << std::endl;

    Foo f1{42, "Hello", 0};
    Foo f2{32, "World", 0};

    std::cout << "(f1 < f2) : " << (f1 < f2) << std::endl;
    std::cout << "(f2 < f1) : " << (f2 < f1) << std::endl;

    auto myTuple = std::make_tuple("Hello world.", 42);
    auto foo = std::make_from_tuple<Foo2>(myTuple);

    std::cout << foo.getStr() << ", " << foo.getInt() << std::endl;

    std::cout << apply(add, std::make_tuple(50, 30)) << std::endl;

    return 0;
}