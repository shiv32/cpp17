
#include <iostream>
#include <type_traits>
#include "mytemplate.hpp"

//----------------------------------
// template <typename T>
// void printTraits(const char *name)
// {
//     std::cout << "Inspecting: " << name << "\n";
//     std::cout << "  is const: " << std::is_const<std::remove_reference_t<T>>::value << "\n";
//     std::cout << "  is reference: " << std::is_reference<T>::value << "\n";
//     std::cout << "  is const reference: " << (std::is_reference<T>::value && std::is_const<std::remove_reference_t<T>>::value) << "\n";
//     std::cout << "  is lvalue ref: " << std::is_lvalue_reference<T>::value << "\n";
//     std::cout << "  is rvalue ref: " << std::is_rvalue_reference<T>::value << "\n";
//     std::cout << "  is value: " << (!std::is_reference<T>::value) << "\n";
//     std::cout << "\n";
// }

// template <typename T>
// void analyze(T &&var, const char *name)
// {
//     printTraits<T>(name);
// }
//----------------------------------

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // auto strips reference and const qualifiers,
    // s1 is of type string, and thus a copy is made.
    auto s1 = getString();
    std::cout << "s1 : " << s1 << std::endl;
    // analyze(s1, "s1");

    // you can explicitly make it a reference and mark it const
    const auto &s2 = getString();
    std::cout << "s2 : " << s2 << std::endl;
    // analyze(s2, "s2");

    // use decltype, which does not strip
    // there is code duplication specify getString() twice
    decltype(getString()) s3 = getString();
    std::cout << "s3 : " << s3 << std::endl;
    // analyze(s3, "s3");

    // this is solved with decltype(auto)
    decltype(auto) s4 = getString();
    std::cout << "s4 : " << s4 << std::endl;
    // analyze(s4, "s4");

    //--------------------------------------------------------------------------
    const int &a = 2;
    const int &b = 2;

    // C++14
    auto result = add(a, b);
    std::cout << "add : " << result << std::endl;
    // analyze(result, "result");

    decltype(auto) result2 = add2(a, b);
    std::cout << "add2 : " << result2 << std::endl;
    // analyze(result2, "result2");

    // Before C++14
    decltype(auto) result3 = add4(2, 5);
    std::cout << "add3 : " << result3 << std::endl;
    // analyze(result3, "result3");

    return 0;
}