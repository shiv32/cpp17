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

//------------------ typename enable_if<..., bool>::type, fun return bool type ----------------------------------------
template <typename T1, typename T2>
typename std::enable_if<std::is_same_v<T1, T2>, bool>::type check_type(const T1 &t1, const T2 &t2)
{
    std::cout << "'" << t1 << "' and '" << t2 << "' ";
    std::cout << "are the same types." << std::endl;
    return true;
}

template <typename T1, typename T2>
typename std::enable_if<!std::is_same_v<T1, T2>, bool>::type check_type(const T1 &t1, const T2 &t2)
{
    std::cout << "'" << t1 << "' and '" << t2 << "' ";
    std::cout << "are different types." << std::endl;
    return false;
}

//------------------------------- enable_if_t<..., bool>, fun return bool type ------------------------------------------------------
// template <typename T1, typename T2>
// std::enable_if_t<std::is_same_v<T1, T2>, bool> check_type(const T1 &t1, const T2 &t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are the same types." << std::endl;
//     return true;
// }

// template <typename T1, typename T2>
// std::enable_if_t<!std::is_same_v<T1, T2>, bool> check_type(const T1 &t1, const T2 &t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are different types." << std::endl;
//     return false;
// }

//--------------------------------- fun no return ------------------------------------------------------
// template <typename T1, typename T2>
// std::enable_if_t<std::is_same_v<T1, T2>, void> check_type(const T1 &t1, const T2 &t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are the same types." << std::endl;
// }

// template <typename T1, typename T2>
// std::enable_if_t<!std::is_same_v<T1, T2>, void> check_type(const T1 &t1, const T2 &t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are different types." << std::endl;
// }

//----------------------------------- fun no return --------------------------------------------------------
// template<typename T1, typename T2>
// std::enable_if_t<std::is_same_v<T1, T2>> check_type(const T1& t1, const T2& t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are the same types." << std::endl;
// }

// template<typename T1, typename T2>
// std::enable_if_t<!std::is_same_v<T1, T2>> check_type(const T1& t1, const T2& t2)
// {
//     std::cout << "'" << t1 << "' and '" << t2 << "' ";
//     std::cout << "are different types." << std::endl;
// }

//----------------------------------- enable_if on a set of constructors -------------------------------------
class MyClass
{
public:
    /*
        int = 0 = default value for a dummy template parameter used only for SFINAE.

        template<int N = 0>
        struct A {};

        A<> a;   // N defaults to 0

    */

    // Enabled only for integral types
    // template<typename T, int = 0>, int = 0 is a default template argument.
    template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
    explicit MyClass(T v)
    {
        std::cout << "integral ctor\n";
    }

    // Enabled only for floating-point types
    template <typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0> // template<typename T, int = 0>
    explicit MyClass(T v)
    {
        std::cout << "floating ctor\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    check_type(1, 32);
    check_type(1, 3.01);
    using namespace std::string_literals;
    check_type(3.01, "Test"s);

    // enable_if on a set of constructors
    MyClass a(10);   // integral ctor
    MyClass b(3.14); // floating ctor

    return 0;
}