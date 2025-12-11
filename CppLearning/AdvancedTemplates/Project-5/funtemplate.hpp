#pragma once
#include <iostream>

static const size_t NOT_FOUND = static_cast<size_t>(-1); // sentinel value

template <typename T>
size_t Find(const T &value, const T *arr, size_t size)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i; // Found it; return the index
        }
    }
    return NOT_FOUND; // Failed to find it; return NOT_FOUND
}

template <typename T, size_t N>
size_t Find(const T &value, const T (&arr)[N])
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
    
    return Find(value, arr, N);
}

//---------- Function partial specialization -------------
/*
Following the syntax for class template partial specialization.
Syntax declares a partial specialization of the function template,
which the C++ standard does not allow.

template <typename T>
size_t Find<T *>(T *const &value, T *const *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*arr[i] == *value)
        {
            return i; // Found it; return the index
        }
    }
    return NOT_FOUND; // failed to find it; return NOT_FOUND
}

*/

template <typename T>
size_t Find(T *const &value, T *const *arr, size_t size)
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        if (*arr[i] == *value)
        {
            return i; // Found it; return the index
        }
    }
    return NOT_FOUND; // failed to find it; return NOT_FOUND
}
