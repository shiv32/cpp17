#include <iostream>

int &increment(int &x)
{
    ++x;
    return x;
}

int square(int x)
{
    return x * x;
}

// void show(int &)
// {
//     std::clog << __PRETTY_FUNCTION__ << std::endl;
// }

void show(const int &)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

void show(int &&)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int x = 5;

    // show(x);    // calls the non-const version, lvalue reference
    // show(5);    // calls the const version, rvalue reference

    // show(++x); // calls the non-const version, lvalue reference
    // show(x++); // calls the const version, rvalue reference

    // show(increment(x)); // calls the non-const version, lvalue reference
    // show(square(x));    // calls the const version, rvalue reference

    const int MAX = 10;
    show(MAX); // calls the const version

    return 0;
}