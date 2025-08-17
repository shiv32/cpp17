#include <iostream>

template <typename T>
T max(T a, T b)
{
    // if b < a then yield a else yield b
    return b < a ? a : b;
}

// template <class T>
// T max(T a, T b)
// {
//     return b < a ? a : b;
// }

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}
