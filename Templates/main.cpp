/*

Template typeid

g++ main.cpp -o test

*/

#include <iostream>

template <typename T>
T findMax(T a, T b)
{
    std::cout<<"Template type : " << typeid(T).name() << std::endl;
    
    return (a > b) ? a : b;
}

int main()
{
    std::cout << findMax(2, 4) << std::endl;

    std::cout << findMax(4.6f, 8.3f) << std::endl;

    return 0;
}