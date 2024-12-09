/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Storing references in a vector
 *        Adding and Removing Elements
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <functional> //std::ref

template <typename T>
void printVector(const std::vector<T> &v)
{

    for (auto &element : v)
    {
        std::cout << element << " ";
    }

    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //----------------(Storing references in a vector)--------------------------
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Create a vector of references to strings.
    std::vector<std::reference_wrapper<std::string>> vec{std::ref(str1)};

    vec.push_back(std::ref(str2)); // push_back() works as well.

    // Modify the string referred to by the second reference in the vector.
    vec[1].get() += "!";

    // The end result is that str2 is actually modified.
    std::cout << str1 << " " << str2 << std::endl;

    //---------------(Adding and Removing Elements)------------------------------
    std::vector<int> vectorOne = {1, 2, 3, 5};
    std::vector<int> vectorTwo;

    // Oops, we forgot to add 4. Insert it in the correct place
    vectorOne.insert(cbegin(vectorOne) + 3, 4);

    // Add elements 6 through 10 to vectorTwo
    for (int i = 6; i <= 10; i++)
    {
        vectorTwo.push_back(i);
    }

    printVector(vectorOne);
    printVector(vectorTwo);

    // Add all the elements from vectorTwo to the end of vectorOne
    vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));
    printVector(vectorOne);

    // Now erase the numbers 2 through 5 in vectorOne
    vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
    printVector(vectorOne);

    // Clear vectorTwo entirely
    vectorTwo.clear();

    // And add 10 copies of the value 100
    vectorTwo.insert(cbegin(vectorTwo), 10, 100);

    // Decide we only want 9 elements
    vectorTwo.pop_back();
    printVector(vectorTwo);

    return 0;
}