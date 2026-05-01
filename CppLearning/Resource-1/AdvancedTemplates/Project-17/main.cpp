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
#include <type_traits>

namespace mtest
{
    /*
      Note that you don’t need to write these specializations yourself;
      they are part of the Standard Library.
    */

    template <class T, T v>
    struct integral_constant
    {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant<T, v>;
        constexpr operator value_type() const noexcept { return value; }
        constexpr value_type operator()() const noexcept { return value; }
    };

    template <bool B>
    using bool_constant = integral_constant<bool, B>;

    using true_type = bool_constant<true>;
    using false_type = bool_constant<false>;

    template <typename T>
    struct is_integral //: public true_type
    {
    };

    // is_integral can be specialized for type bool
    template <>
    struct is_integral<bool> : public true_type
    {
    };
}

namespace example
{
    // Using Type Categories

    template <typename T>
    void process_helper(const T &t, std::true_type) // nameless parameter of type true_type
    {
        std::cout << t << " is an integral type." << std::endl;
    }

    template <typename T>
    void process_helper(const T &t, std::false_type) // nameless parameter of type false_type
    {
        std::cout << t << " is a non-integral type." << std::endl;
    }

    template <typename T>
    void process(const T &t)
    {
        process_helper(t, typename std::is_integral<T>::type());
    }
}

namespace example2
{
    // Using Type Categories

    template <typename T>
    void process(const T &t)
    {
        if constexpr (std::is_integral_v<T>)
        {
            std::cout << t << " is an integral type." << std::endl;
        }
        else
        {
            std::cout << t << " is a non-integral type." << std::endl;
        }
    }
}

namespace example3
{
    // Using Type Relations

    template <typename T1, typename T2>
    void same(const T1 &t1, const T2 &t2)
    {
        bool areTypesTheSame = std::is_same_v<T1, T2>;

        std::cout << "'" << t1 << "' and '" << t2 << "' are ";
        std::cout << (areTypesTheSame ? "the same types." : "different types.") << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::clog << mtest::true_type::value << std::endl;
    // std::clog << mtest::false_type::value << std::endl;

    // // This is used in template metaprogramming, not printing
    // // true_type::type // alias to true_type
    // // false_type::type // alias to false_type

    // std::clog << mtest::true_type::type() << std::endl;
    // std::clog << mtest::false_type::type() << std::endl;

    //-------------------
    // if (std::is_integral<bool>::value)
    // {
    //     std::cout << "bool is integral" << std::endl;
    // }
    // else
    // {
    //     std::cout << "bool is not integral" << std::endl;
    // }

    // if (std::is_integral<int>::value)
    // {
    //     std::cout << "int is integral" << std::endl;
    // }
    // else
    // {
    //     std::cout << "int is not integral" << std::endl;
    // }

    // if (std::is_class<std::string>::value)
    // {
    //     std::cout << "string is a class" << std::endl;
    // }
    // else
    // {
    //     std::cout << "string is not a class" << std::endl;
    // }

    //-------------
    // if (std::is_integral_v<int>) // C++17
    // {
    //     std::cout << "int is integral" << std::endl;
    // }
    // else
    // {
    //     std::cout << "int is not integral" << std::endl;
    // }

    // if (std::is_class_v<std::string>) // C++17
    // {
    //     std::cout << "string is a class" << std::endl;
    // }
    // else
    // {
    //     std::cout << "string is not a class" << std::endl;
    // }
    //------------
    // Using Type Categories
    // example::process(123);
    // example::process(2.2);
    // using namespace std::string_literals;
    // example::process("Test"s);

    // example2::process(123);
    // example2::process(2.2);
    // using namespace std::string_literals;
    // example2::process("Test"s);

    // Using Type Relations
    example3::same(1, 32);
    example3::same(1, 3.01);
    using namespace std::string_literals;
    example3::same(3.01, "Test"s);

    return 0;
}