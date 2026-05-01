/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   The Individual Derived Classes
                Writing the StringSpreadsheetCell and DoubleSpreadsheetCell classes is just a matter of
                implementing the functionality that is defined in the parent.

                If a derived class does not implement all pure virtual methods from the base class, then
                the derived class is abstract as well, and clients will not be able to instantiate objects of
                the derived class.

            StringSpreadsheetCell Class Definition
                The first step in writing the class definition of StringSpreadsheetCell is to inherit from
                SpreadsheetCell.
                Next, the inherited pure virtual methods are overridden, this time without being set to zero.

            StringSpreadsheetCell Implementation
                The source file for StringSpreadsheetCell contains the implementation of the methods.

            DoubleSpreadsheetCell Class Definition and Implementation
                The double version follows a similar pattern, but with different logic.

            Leveraging Polymorphism
                Now that the SpreadsheetCell hierarchy is polymorphic, client code can take advantage of the
                many benefits that polymorphism has to offer.

            Future Considerations
                The new implementation of the SpreadsheetCell hierarchy is certainly an improvement from an
                object-oriented design point of view.
                Yet, it would probably not suffice as an actual class hierarchy for a real-world spreadsheet program
                for several reasons.

                First, despite the improved design, one feature is still missing: the ability to convert from one cell
                type to another.
                By dividing them into two classes, the cell objects become more loosely integrated.

                To provide the ability to convert from a DoubleSpreadsheetCell to a StringSpreadsheetCell,
                you could add a converting constructor, also known as a typed constructor.
                It has a similar appearance as a copy constructor, but instead of a reference to an object of the same
                class, it takes a reference to an object of a sibling class.
                Note also that you now have to declare a default constructor, which can be explicitly defaulted,
                because the compiler stops generating one as soon as you declare any constructor yourself.

                        WARNING You can always cast up the hierarchy, and you can sometimes
                                cast down the hierarchy.
                                Casting across the hierarchy is possible by changing
                                the behavior of the cast operator, or by using reinterpret_cast(),
                                neither of which is recommended.

                Second, the question of how to implement overloaded operators for cells is an interesting one, and
                there are several possible solutions.

                    One approach is to implement a version of each operator for every combination of cells.
                    With only two derived classes, this is manageable.
                    There would be an operator+ function to add two double cells, to add two string cells,
                    and to add a double cell to a string cell.

                    Another approach is to decide on a common representation.
                    The preceding implementation already standardizes on a string as a common representation of sorts.
                    A single operator+ function could cover all the cases by taking advantage of this common representation.

                    The result of this addition doesn’t really add the numbers together.
                    It converts the double cells into string cells and concatenates the strings.



 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include <vector>

#include "SpreadsheetCell.hpp"
#include "StringSpreadsheetCell.hpp"
#include "DoubleSpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<std::unique_ptr<SpreadsheetCell>> cellArray;

    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<DoubleSpreadsheetCell>());

    cellArray[0]->set("hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    std::cout << "Vector values are ["
              << cellArray[0]->getString() << ","
              << cellArray[1]->getString() << ","
              << cellArray[2]->getString() << "]"
              << std::endl;

    DoubleSpreadsheetCell myDbl;
    myDbl.set(8.4);
    StringSpreadsheetCell result = myDbl + myDbl;

    std::cout << "result: "
              << result.getString() << std::endl;

    DoubleSpreadsheetCell myDbl1;
    DoubleSpreadsheetCell myDbl2;
    myDbl1.set(8.4);
    myDbl2.set(9.4);
    result = myDbl1 + myDbl2;

    std::cout << "result: "
              << result.getString() << std::endl;

    return 0;
}