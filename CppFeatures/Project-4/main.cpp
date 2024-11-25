/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Function Templates

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <cstring> // For strcat and strlen

// int sum(int a, int b)
// {
//    return a+b;
// }

// double sum(double a, double b)
// {
//    return a+b;
// }

template <typename T>
T sum(T a, T b)
{
    std::cout << std::endl;
    std::cout << "template type : " << typeid(T).name() << std::endl;
    return a + b;
}

// explicit instatiation
template char sum(char x, char y);

// explicit specialization
template <>
char *sum<char *>(char *str1, char *str2)
{
    // Calculate the lengths of the input strings
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Allocate memory for the concatenated result
    char *result = new char[len1 + len2 + 1]; // +1 for the null terminator

    // Copy the first string into result
    strcpy(result, str1);

    // Concatenate the second string
    strcat(result, str2);

    return result;
}

template <typename T, typename T2>
T2 sum2(T a, T b)
{
    return a + b;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int s1 = sum(3, 8);
    double s2 = sum(3.5, 8.3);
    // double s = sum<double>(3.5, 8.3);

    // double s = sum2(3.5, 8.3); //compilation error
    // double s = sum2<double,double>(3.5,8.3);

    // std::cout << "sum : " << s << std::endl;

    //-------------------------------------------------------------------

    int (*pfn)(int, int) = sum;
    std::cout << "sum fpn : " << pfn(4, 7) << std::endl;

    //-------------------------------------------------------------------
    char *b{"B"};
    char *a{"A"};
    char *c{"C"};

    auto s = sum(b, a);

    std::cout << "sum char : " << s << std::endl;

    s = sum(s, c);

    std::cout << "sum char : " << s << std::endl;

    return 0;
}