/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Function Objects vs Function Pointers
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

// function object
struct FnGreater
{
    int m_Value{};

    FnGreater(int value) : m_Value{value}
    {
    }

    bool operator()(int x) const // function call operator
    {
        // return x > 3;
        return x > m_Value;
    }
};

// function object
struct FnLess
{
    int m_Value{};

    FnLess(int value) : m_Value{value}
    {
    }

    bool operator()(int x) const // function call operator
    {
        return x < m_Value;
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int arr[] = {1, 2, 3, 4, 5};

    // auto found = Find_if(Begin(arr), End(arr), Less3); // function pointer
    // found = Find_if(Begin(arr), End(arr), Greater3);  // function pointer

    auto found = Find_if(Begin(arr), End(arr), FnLess{3}); // function object
    found = Find_if(Begin(arr), End(arr), FnGreater{5});   // function object

    return 0;
}