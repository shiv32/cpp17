/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Strings
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <bitset>

void bitsetBasics()
{
    std::bitset<10> myBitset;

    myBitset.set(3);
    myBitset.set(6);

    myBitset[8] = true;

    myBitset[9] = myBitset[3];

    if (myBitset.test(3))
    {
        std::cout << "Bit 3 is set!" << std::endl;
    }

    std::cout << myBitset << std::endl;
}

void bitwiseOperators()
{
    auto str1 = "0011001100";
    auto str2 = "0000111100";

    std::bitset<10> bitsOne(str1);
    std::bitset<10> bitsTwo(str2);

    auto bitsThree = bitsOne & bitsTwo;

    std::cout << bitsThree << std::endl;

    bitsThree <<= 4;

    std::cout << bitsThree << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // bitsetBasics();

    bitwiseOperators();

    return 0;
}
