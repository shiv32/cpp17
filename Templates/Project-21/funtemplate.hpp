#pragma once

#include <optional>
#include <cstring>

template <typename T>
std::optional<size_t> Find(const T &value, const T *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i; // Found it; return the index
        }
    }
    return std::nullopt; // Indicate that the value was not found
}

template <typename T, size_t N>
std::optional<size_t> Find(const T &value, const T (&arr)[N])
{
    return Find(value, arr, N);
}

//------------------------------ Function Template Specialization -------------------------------------

template <>
std::optional<size_t> Find<const char *>(const char *const &value, const char *const *arr, size_t size)
//std::optional<size_t> Find(const char* const& value, const char* const* arr, size_t size)
{
    std::cout<<"---- Specialization called -----------------"<<std::endl;

    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(arr[i], value) == 0)
        {
            return i; // Found it; return the index
        }
    }
     return std::nullopt; // Indicate that the value was not found
}