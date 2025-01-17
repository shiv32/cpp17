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
#include "Integer.h"

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
// template char sum(char x, char y);

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

// non type template argument
template <int size>
void print()
{
    // size++;//not allowed its const
    char buffer[size];

    std::cout << "size : " << size << std::endl;
}

// template <typename T>
// T Sum(T *parr, int size)
// {

//     T sum{};

//     for (int i = 0; i < size; ++i)
//     {
//         sum += parr[i];
//     }
//     return sum;
// }

template <typename T, int size>
T Sum(T (&parr)[size])
{

    T sum{};

    for (int i = 0; i < size; ++i)
    {
        sum += parr[i];
    }
    return sum;
}

// template <typename T>
// void Print(std::initializer_list<T> args)
// {
//     for(auto const &x:args)
//     {
//       std::cout<<x<<" "<<std::endl;
//     }
// }

// base case function for variadic template
void Print()
{
    std::cout << std::endl;
}

// // template parameter pack
// template <typename T, typename ...params>
// // funtion parameter pack
// void Print(T a, params ...args)
// {
//     // std::cout << sizeof ...(args) << std::endl;
//     // std::cout << sizeof ...(params) << std::endl;

//     //std::cout << a << ", ";

//      std::cout<<a;

//      if(sizeof...(args) != 0)
//      {
//            std::cout<<", ";
//      }

//     Print(args...);
// }

// // template parameter pack
// template <typename T, typename ...params>
// // funtion parameter pack
// void Print(const T &a, const params &...args) //L-value reference
// {
//     // std::cout << sizeof ...(args) << std::endl;
//     // std::cout << sizeof ...(params) << std::endl;

//     //std::cout << a << ", ";

//      std::cout<<a;

//      if(sizeof...(args) != 0)
//      {
//            std::cout<<", ";
//      }

//     Print(args...);
// }

// template parameter pack
template <typename T, typename... params>
// funtion parameter pack
void Print(T &&a, params &&...args) // R-value reference
{
    // std::cout << sizeof ...(args) << std::endl;
    // std::cout << sizeof ...(params) << std::endl;

    // std::cout << a << ", ";

    std::cout << a;

    if (sizeof...(args) != 0)
    {
        std::cout << ", ";
    }

    Print(std::forward<params>(args)...);
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // int s1 = sum(3, 8);
    // double s2 = sum(3.5, 8.3);
    // double s = sum<double>(3.5, 8.3);

    // double s = sum2(3.5, 8.3); //compilation error
    // double s = sum2<double,double>(3.5,8.3);

    // std::cout << "sum : " << s << std::endl;

    //-------------------------------------------------------------------

    // int (*pfn)(int, int) = sum;
    // std::cout << "sum fpn : " << pfn(4, 7) << std::endl;

    //----------------------------------------------------------------------------
    // char a = 'A'; // ASCII value: 65
    // char b = 'B'; // ASCII value: 66

    // unsigned char a = 'A';
    // unsigned char b = 'B';

    // char result = sum(a, b);

    // unsigned char result = sum(a, b);

    // std::cout << "The sum of '" << a << "' and '" << b << "' is: " << static_cast<int>(result) << "\n";

    //---------------------------------(explicit specialization)----------------------------------

    // Compiler: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
    // char *b{"B"};
    // char *a{"A"};
    // char *c{"C"};

    // char b[]{"B"};
    // char a[]{"A"};
    // char c[]{"C"};

    // auto s = sum(b, a);

    // std::cout << "sum char : " << s << std::endl;

    // s = sum(s, c);

    // std::cout << "sum char : " << s << std::endl;

    //-----------------------------(non type template argument)------------------------------------

    // print<30>();

    // int i = 30;

    // print<i>(); //complir error

    // print<sizeof(i)>();

    // int arr[]{30, 10, 90, 70};

    // auto it = std::begin(arr);

    // int (&ref)[4] = arr;

    // int sum = Sum(arr,4);
    // int sum = Sum(arr);

    // std::cout << "sum : " << sum << std::endl;
    //-----------------------------------(variadic template)--------------------------------------------

    //Print({10,20,30,40});

    // Print({10,20,30.5,40}); //compile time error template arg deduction

    //Print(1, 2, 3.4, "r", 's'); // variadic template

     Integer val{1};

    Print(0, val, Integer{2});

    return 0;
}