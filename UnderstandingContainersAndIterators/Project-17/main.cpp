/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  vector<bool> Specialization Example-2
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <bitset>

// Function to inspect raw storage of std::vector<bool>
void printPackedStorage(const std::vector<bool> &vec)
{
    std::cout << "Vector<bool> contents: ";
    for (bool b : vec)
    {
        std::cout << b;
    }
    std::cout << std::endl;

    // Inspect packed storage using bitset representation
    size_t numBits = vec.size();
    size_t numWords = (numBits + sizeof(unsigned long) * 8 - 1) / (sizeof(unsigned long) * 8);

    std::cout << "Packed Storage Approximation (bitwise representation):" << std::endl;
    for (size_t i = 0; i < numWords; ++i)
    {
        std::bitset<sizeof(unsigned long) * 8> bits;
        for (size_t j = 0; j < sizeof(unsigned long) * 8; ++j)
        {
            size_t idx = i * sizeof(unsigned long) * 8 + j;
            if (idx < numBits)
            {
                bits[j] = vec[idx];
            }
        }
        std::cout << "Word " << i << ": " << bits << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<bool> vec = {true, false, true, true, false, false, true, true, false, true};

    printPackedStorage(vec);

    return 0;
}