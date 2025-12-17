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

namespace ptv1
{
    template <typename TupleType, int n>
    class tuple_print
    {
    public:
        tuple_print(const TupleType &t)
        {
            tuple_print<TupleType, n - 1> tp(t);
            std::cout << std::get<n - 1>(t) << std::endl;
        }
    };

    template <typename TupleType>
    class tuple_print<TupleType, 0>
    {
    public:
        tuple_print(const TupleType &) {}
    };

}

namespace ptv2
{
    template <typename TupleType, int n>
    class tuple_print_helper
    {
    public:
        tuple_print_helper(const TupleType &t)
        {
            tuple_print_helper<TupleType, n - 1> tp(t);
            std::cout << std::get<n - 1>(t) << std::endl;
        }
    };

    template <typename TupleType>
    class tuple_print_helper<TupleType, 0>
    {
    public:
        tuple_print_helper(const TupleType &) {}
    };

    template <typename T>
    void tuple_print(const T &t)
    {
        tuple_print_helper<T, std::tuple_size<T>::value> tph(t);
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    using MyTuple = std::tuple<int, std::string, bool>;
    MyTuple t1(16, "Test", true);
    ptv1::tuple_print<MyTuple, std::tuple_size<MyTuple>::value> tp(t1);

    //-----------
    
    auto t2 = std::make_tuple(167, "Testing", false, 2.3);
    ptv2::tuple_print(t2); // in function, compiler can deduce template parameter automatically from the supplied argument

    return 0;
}