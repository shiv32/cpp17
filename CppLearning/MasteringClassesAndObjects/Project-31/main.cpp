/*
    BUILDING STABLE INTERFACES

        Classes are the main unit of abstraction in C++.

        You should apply the principles of abstraction to your classes to separate the interface
        from the implementation as much as possible.

        You should make all data members private and provide getter and setter methods for them.
        This is how the SpreadsheetCell class is implemented.

    Using Interface and Implementation Classes

        The basic principle is to define two classes for every class you want to write: the interface class and
        the implementation class.

        The implementation class is identical to the class you would have written if you
        were not taking this approach.

        The interface class presents public methods identical to those of the implementation class,
        but it only has one data member: a pointer to an implementation class object.

        This is called the pimpl idiom, private implementation idiom, or bridge pattern.

        The interface class method implementations simply call the equivalent methods on the implementation
        class object.
        The result of this is that no matter how the implementation changes, it has no impact on the public
        interface class.

        This reduces the need for recompilation.

        None of the clients that use the interface class need to be recompiled if the
        implementation (and only the implementation) changes.

        Note :
                This idiom only works if the single data member is a pointer to the implementation class.
                If it were a by-value data member, the clients would have to be recompiled when the definition
                of the implementation class changes.

                With stable interface classes, build times can be reduced.
                    Note -> In vs code click on build and see the below line in CMake output window

                            [driver] Build completed: 00:00:05.947

                            Build Time: The time shown (00:00:05.947)

                            Hours:          The first 00 indicates the hours.
                            Minutes:        The second 00 indicates the minutes.
                            Seconds:        The third 05 indicates the seconds.
                            Milliseconds:   The 947 indicates milliseconds (i.e. 183 ms).
*/

#include "Spreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "--------------------------------------------------" << std::endl;

    // Spreadsheet s1(2, 2), s2(4, 3);
    auto s1 = std::make_shared<Spreadsheet>(2, 2);
    auto s2 = std::make_shared<Spreadsheet>(4, 3);

    std::cout << "s1 Width : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height : " << s1->getHeight() << std::endl;

    // std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    // std::cout << "s1 Height : " << s1.getHeight() << std::endl;

    s1 = s2;

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "s1 Width after assignment : " << s1->getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1->getHeight() << std::endl;

    // std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    // std::cout << "s1 Height : " << s1.getHeight() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}