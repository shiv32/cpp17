/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Implementing a Dynamic Sized Array
 * @version 0.1
 * @date 2024-09-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Dynamic_array.hpp"
#include "Student.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int nStudents{};
    std::cout << "Enter number of students in class 1 : ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);

    for (int i = 0; i < nStudents; i++)
    {
        std::cout << "Enter name and class of student " << i + 1 << ": ";
        std::string name;
        int standard;
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    // Now, let’s try to access the student out of range in the array
    try
    {
        // class1 student set out of range without exception
        // class1[nStudents] = student{"John", 8}; // No exception, undefined behavior

        class1.at(nStudents) = student{"John", 8}; // Will throw exception
    }
    catch (...)
    {
        std::cout << "Exception caught" << std::endl;
    }

    auto class2 = class1; // Deep copy

    std::cout << "Second class after initialized using first array : " << class2.to_string() << std::endl;

    auto class3 = class1 + class2; // Combines both classes and creates a bigger one

    std::cout << "Combined class : ";
    std::cout << class3.to_string() << std::endl;

    return 0;
}