/*
   Default Arguments
        Specify defaults for function and method parameters in the prototype.
        If the user specifies those arguments, the default values are ignored.
        If the user omits those arguments, the default values are used.

        You can only provide defaults for a continuous list of parameters starting from
        the rightmost parameter.

        eg. Assign default values to the width and height in your Spreadsheet constructor.

            Spreadsheet(size_t width = 100, size_t height = 100);

        Specify the default arguments only in the method declaration, but not in the definition.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto sheet1 = std::make_shared<Spreadsheet>();
    //auto sheet2 = std::make_shared<Spreadsheet>(5);
    //auto sheet3 = std::make_shared<Spreadsheet>(5, 6);

    // std::cout << "Cell2 value at (1,1) string : " << cell2->getString() << std::endl;

    return 0;
}