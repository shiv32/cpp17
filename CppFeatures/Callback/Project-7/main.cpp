/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Function Object Internals
 *
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

bool Greater3(int x)
{
    return x > 3;
}

bool Less3(int x)
{
    return x < 3;
}

// template <typename T>
// T Find_if(T beg, T end)
// {

//     while (beg != end)
//     {
//         // if (Greater3(*beg))
//         if (Less3(*beg))
//             break;

//         ++beg;
//     }

//     return beg;
// }

// template <typename T, typename ElemType>
// T Find_if(T beg, T end, bool (*Pfn)(ElemType elem))
// {
//     while (beg != end)
//     {
//         if (Pfn(*beg))
//             break;

//         ++beg;
//     }

//     return beg;
// }

template <typename T, typename ElemType>
T Find_if(T beg, T end, ElemType Pfn)
{
    while (beg != end)
    {
        if (Pfn(*beg))
            break;

        ++beg;
    }

    return beg;
}

//function object
struct FnGreater
{
    int m_Value{};

    FnGreater(int value) : m_Value{value}
    {
    }

    bool operator()(int x) const
    {
        // return x > 3;
        return x > m_Value;
    }
};

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

    /*
     auto found = Find(Begin(arr), End(arr), elem);

        if (found != End(arr))
        {
            std::cout << "Found" << std::endl;
        }
        else
        {
            std::cout << "Not Found" << std::endl;
        }
    */

    /*
    auto found = Find_if(Begin(arr), End(arr));

        if (found != End(arr))
        {
            std::cout << "Found " << *found << std::endl;
        }
        else
        {
            std::cout << "Not Found" << std::endl;
        }
    */

    // auto found = Find_if(Begin(arr), End(arr),Less3);  //function pointer used
    // auto found = Find_if(Begin(arr), End(arr), Greater3);

    // FnGreater fn;
    //  auto found = Find_if(Begin(arr), End(arr), fn);  //function object
    //  auto found = Find_if(Begin(arr), End(arr), FnGreater{}); // function object

    // auto found = Find_if(Begin(arr), End(arr), Greater3); // function pointer
    //  auto found = Find_if(Begin(arr), End(arr), FnGreater{});   // function object
    auto found = Find_if(Begin(arr), End(arr), FnGreater{4}); // function object

    if (found != End(arr))
    {
        std::cout << "Found " << *found << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}