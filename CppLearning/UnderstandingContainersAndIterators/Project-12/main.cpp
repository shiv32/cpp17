/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Move Semantics
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

std::vector<int> createVectorOfSize(size_t size)
{
    std::vector<int> vec(size);

    int contents = 0;

    for (auto &i : vec)
    {
        i = contents++;
    }

    return vec;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<int> myVector;

    myVector = createVectorOfSize(10); // calls the copy assignment operator.

    for (auto const &element : myVector)
    {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    //-----------------------------------------------------------------------

    std::vector<std::string> vec;

    std::string myElement(5, 'a'); // Constructs the string "aaaaa"

    vec.push_back(myElement); // makes a copy of myElement and puts it in the vector.

    vec.push_back(move(myElement)); // myElement should be moved into the vector.

    vec.push_back(std::string(5, 'a')); // triggers a call to the move version

    for (auto const &element : vec)
    {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    return 0;
}