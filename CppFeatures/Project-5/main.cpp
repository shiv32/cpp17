/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief callback introduction

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

template <typename T, int size>
void Print(T (&ref)[size])
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << ref[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T, int size>
T *Begin(T (&ref)[size])
{
    return ref;
}

template <typename T, int size>
T *End(T (&ref)[size])
{
    return (ref + size);
}

template <typename T, typename ElemType>
T Find(T beg, T end, const ElemType &elem)
{

    while (beg != end)
    {
        if (*beg == elem)
            break;

        ++beg;
    }

    return beg;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr[] = {1, 2, 3, 4, 5};

    Print(arr);
    int elem{3};

    /*
   int i = 0;

   for (; i < 5; ++i)
   {

       if (arr[i] == elem)
       {
           break;
       }
   }

   if (i != 5)
   {
       std::cout << "Found" << std::endl;
   }
    */

    auto found = Find(Begin(arr), End(arr), elem);

    if (found != End(arr))
    {
        std::cout << "Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}