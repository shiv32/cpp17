/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   Referring to Parent Names part 2
                Calling the parent version of the current method is a commonly
                used pattern in C++.
                    eg.  Imagine a class hierarchy of book types.

                             <- Technical
                            /
                        Book
                            \
                             <- Paperback <- Romance

                Because each lower class in the hierarchy further specifies the type
                of book, a method that gets the description of a book really needs
                to take all levels of the hierarchy into consideration.

                This can be accomplished by chaining to the parent method.

                The Book base class has two virtual methods: getDescription() and getHeight().

                All derived classes override getDescription(), but only the Romance class overrides getHeight() by calling
                getHeight() on its parent class (Paperback) and dividing the result by two.

                Paperback does not override getHeight(), but C++ walks up the class hierarchy to find a class that
                implements getHeight().

                In this example, Paperback::getHeight() resolves to Book::getHeight().

 *
 * @version 0.1
 * @date 2024-09-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Romance.hpp"
#include "Technical.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Romance novel;
    // Book book;

    // std::cout << novel.getDescription() << std::endl; // Outputs "Romance Paperback Book"
    // std::cout << book.getDescription() << std::endl;  // Outputs "Book"
    // std::cout << novel.getHeight() << std::endl;      // Outputs "60"
    // std::cout << book.getHeight() << std::endl;       // Outputs "120"

    // smart pointers
    auto novel = std::make_unique<Romance>();
    auto book = std::make_unique<Book>();
    auto technical = std::make_unique<Technical>();

    std::cout << novel->getDescription() << std::endl; // Outputs "Romance Paperback Book"
    std::cout << technical->getDescription() << std::endl;  // Outputs "Technical Book"
    std::cout << book->getDescription() << std::endl;  // Outputs "Book"

    std::cout << novel->getHeight() << std::endl;      // Outputs "60"
    std::cout << book->getHeight() << std::endl;       // Outputs "120"

    return 0;
}