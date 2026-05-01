/*
   const static Data Members
        You should use static const (or const static) data members in place
        of global constants when the constants apply only to the class.
        It also called class constants.

        static const data members of integral and enumeration types can be defined and initialized inside the
        class definition without making them inline variables.

        eg.

                // Static const integral type(int, char)
                static const int value = 42;

                 // Static const enumeration type
                enum Color { RED, GREEN, BLUE };
                static const Color favoriteColor = GREEN;

        eg. Make the maximum height and width static const members of the Spreadsheet class.

                static const size_t kMaxHeight = 100;
                static const size_t kMaxWidth = 100;

        Note:-  When you define static const data members of integral types in a header file, 
                you can initialize them directly within the class definition. 
                However, if you need to access their address (which requires the variable to have a storage location), 
                you also need to provide a definition outside the class, typically in a corresponding .cpp file.

*/

#include <iostream>
#include "Spreadsheet.hpp"

class Example
{
public:
        // Static const integral type
        static const int value = 42;

        // Static const enumeration type
        enum Color
        {
                RED,
                GREEN,
                BLUE
        };

        static const Color favoriteColor = GREEN;

        // static const non-integral type
        static const std::string text;

        static const std::string getText()
        {
                return text;
        }
};

// Definition of static const non-integral type outside the class
const std::string Example::text = "Hello, Shiv!";

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

        auto sheet4 = std::make_unique<Spreadsheet>(500, 600); // will set to 100

        std::cout << "sheet4 id : " << sheet4->getId() << std::endl;
        std::cout << "sheet4->getWidth() : " << sheet4->getWidth() << std::endl;
        std::cout << "sheet4->getHeight() : " << sheet4->getHeight() << std::endl;

        std::cout << "Maximum width is: " << Spreadsheet::kMaxWidth << std::endl;
        std::cout << "Maximum height is: " << Spreadsheet::kMaxHeight << std::endl;

        std::cout << "Value: " << Example::value << std::endl;
        std::cout << "Favorite Color: " << Example::favoriteColor << std::endl;
        std::cout << "Text: " << Example::getText() << std::endl;

        return 0;
}