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

namespace v1
{
    template <typename TupleType, int n>
    class tuple_print_helper
    {
    public:
        tuple_print_helper(const TupleType &t)
        {
            if constexpr (n > 1)
            {
                tuple_print_helper<TupleType, n - 1> tp(t);
            }
            std::cout << std::get<n - 1>(t) << std::endl;
        }
    };

    template <typename T>
    void tuple_print(const T &t)
    {
        tuple_print_helper<T, std::tuple_size<T>::value> tph(t);
    }
}

namespace v2
{
    template <typename TupleType, int n>
    void tuple_print_helper(const TupleType &t)
    {
        if constexpr (n > 1)
        {
            tuple_print_helper<TupleType, n - 1>(t);
        }
        std::cout << std::get<n - 1>(t) << std::endl;
    }

    template <typename T>
    void tuple_print(const T &t)
    {
        tuple_print_helper<T, std::tuple_size<T>::value>(t);
    }
}

namespace v3
{
    template <typename TupleType, int n = std::tuple_size<TupleType>::value>
    void tuple_print(const TupleType &t)
    {
        if constexpr (n > 1)
        {
            tuple_print<TupleType, n - 1>(t);
        }
        std::cout << std::get<n - 1>(t) << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto t1 = std::make_tuple(167, "Testing", false, 2.3);

    // v1::tuple_print(t1);
    // v2::tuple_print(t1);
    v3::tuple_print(t1);

    return 0;
}