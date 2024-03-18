#pragma once

#include <optional>

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T &value, const T *arr, size_t size)
{
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
    return Find(value, arr, N);
}