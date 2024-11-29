/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Iterator Safety
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
    std::vector<int> intVector;

    auto iter = end(intVector);

    *iter = 10; // BUG! iter doesn't refer to a valid element.
    */

    /*

      std::vector<int> vectorOne(10);
        std::vector<int> vectorTwo(10);

        // Fill in the vectors.

        // BUG! Possible infinite loop
        for (auto iter = begin(vectorTwo); iter != end(vectorOne); ++iter)
        {
            // Loop body
            std::cout << "infinite loop" << std::endl;
        }

    */

    std::vector<int> intVector(10);

    auto it = begin(intVector);

    it += 5;
    --it;
    *it = 4;

    int i = 0;

    for (const auto &element : intVector)
    {
        std::cout << "index : " << i++ << " value : " << element << std::endl;
    }

    return 0;
}