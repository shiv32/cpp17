#include <iostream>
#include <string>

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

template <typename T>
T foo(T *)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int i = 42;
    std::cout << "max(7,i):" << ::max(7, i) << '\n';

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << '\n';

    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "max(s1,s2): " << ::max(s1, s2) << '\n';

    void *vp = nullptr;
    foo(vp); // OK: deduces void foo(void*)

    return 0;
}
