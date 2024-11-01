/*
Return Type of Function Templates

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "mytemplate.hpp"

int main()
{
    // auto strips reference and const qualifiers, s1 is of type string, and thus a copy is made.
    auto s1 = getString();

    std::cout << "s1 : " << s1 << std::endl;

    // you can explicitly make it a reference and mark it const
    const auto &s2 = getString();

    std::cout << "s2 : " << s2 << std::endl;

    // use decltype, which does not strip
    // there is code duplication specify getString() twice
    decltype(getString()) s3 = getString();

    std::cout << "s3 : " << s3 << std::endl;

    // this is solved with decltype(auto)
    decltype(auto) s4 = getString();

    std::cout << "s4 : " << s4 << std::endl;

    // C++14
    auto result = add(2, 5);

    std::cout << "add : " << result << std::endl;

    decltype(auto) result2 = add2(2, 5);

    std::cout << "add2 : " << result2 << std::endl;

    // Before C++14
    decltype(auto) result4 = add4(2, 5);

    std::cout << "add4 : " << result4 << std::endl;

    return 0;
}