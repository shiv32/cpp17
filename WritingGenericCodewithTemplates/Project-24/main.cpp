#include <iostream>
#include "mytemplate.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // case 1
    auto result = add<long long, int, int>(1, 2);
    std::cout << "result : " << result << std::endl;

    result = add<long long>(1, 3);
    std::cout << "result : " << result << std::endl;

    // case 2
    result = add<int, long long>(1, 5);
    std::cout << "result : " << result << std::endl;

    // case 3
    result = add2(1, 6);
    std::cout << "result : " << result << std::endl;

    return 0;
}