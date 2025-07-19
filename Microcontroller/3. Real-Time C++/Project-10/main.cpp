#include <iostream>
#include <limits>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // This is 31 on a system with 4 byte int.
    // The sign bit is not included in digits.
    constexpr int n_dig = std::numeric_limits<int>::digits;
    std::cout << "The number of digits in an int is: " << n_dig << std::endl;

    // This is 2,147,483,647 if int is 4 bytes.
    constexpr int n_max = std::numeric_limits<int>::max();
    std::cout << "The maximum value of an int is: " << n_max << std::endl;

    // Compile-time check if float conforms to IEEE-754.
    static_assert(std::numeric_limits<float>::is_iec559, "float is not IEEE754 conforming!");

    constexpr bool is_ieee754_conform = std::numeric_limits<float>::is_iec559;
    std::cout << "Is float IEEE-754 conforming? " << (is_ieee754_conform ? "Yes" : "No") << std::endl;

    return 0;
}
