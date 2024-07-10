/*
   static Data Members
        static data member is a data member associated with a class instead of an object.
        static data members is a global variables specific to a class.

        eg. Spreadsheet class definition, including the new static counter data member.

                static size_t sCounter;

        Listing static class members in the class definition, you will have to allocate space for
        them in a source file(in which you place your class method definitions).

        They are initialized to 0 by default.
        you can explicitly initialize them to 0.
        Static pointers are initialized to nullptr.

                size_t Spreadsheet::sCounter;
                        or
                size_t Spreadsheet::sCounter = 0;
        
    Inline Variables
        Starting with C++17, you can declare your static data members as inline.
        The benefit of this is that you do not have to allocate space for them in a source file.

                static inline size_t sCounter = 0;

    Accessing static Data Members within Class Methods
                
                size_t getId() const;
                size_t mId = 0;
                
                Spreadsheet::Spreadsheet(size_t width, size_t height)
                : mId(sCounter++), mWidth(width), mHeight(height)
                {

                }

    Accessing static Data Members Outside Methods
                Access control specifiers apply to static data members.
                   sCounter is private, so it cannot be accessed from outside class methods. 
                   If sCounter was public, you could access it from outside class methods.
                
                eg. sCounter variable is part of the Spreadsheet class with the :: scope resolution operator.

                        int c = Spreadsheet::sCounter;

                 It’s not recommended to have public data members.
                 Grant access to a static data member, implement static get/set methods.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto sheet1 = std::make_unique<Spreadsheet>();

    std::cout << "sheet1 id : " << sheet1->getId() << std::endl;
    std::cout << "sheet1->getWidth() : " << sheet1->getWidth() << std::endl;
    std::cout << "sheet1->getHeight() : " << sheet1->getHeight() << std::endl;

    auto sheet2 = std::make_unique<Spreadsheet>(5);

    std::cout << "sheet2 id : " << sheet2->getId() << std::endl;
    std::cout << "sheet2->getWidth() : " << sheet2->getWidth() << std::endl;
    std::cout << "sheet2->getHeight() : " << sheet2->getHeight() << std::endl;

    auto sheet3 = std::make_unique<Spreadsheet>(5, 6);

    std::cout << "sheet3 id : " << sheet3->getId() << std::endl;
    std::cout << "sheet3->getWidth() : " << sheet3->getWidth() << std::endl;
    std::cout << "sheet3->getHeight() : " << sheet3->getHeight() << std::endl;

    return 0;
}