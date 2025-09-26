/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Standard C-Style Arrays
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>

void standardCStyleArray()
{
    const size_t count = 10;
    int arr[count]; // standard C-style array

    // Initialize each element of the array to the value of its index.
    for (int i = 0; i < count; i++)
    {
        arr[i] = i;
    }

    // Insert the contents of the array at the end of a vector.
    std::vector<int> vec;
    
    //vec.insert(end(vec), arr, arr + count);
    //or
    vec.insert(end(vec), std::cbegin(arr), std::cend(arr));

    // Print the contents of the vector.
    for (const auto &i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    standardCStyleArray();

    return 0;
}
