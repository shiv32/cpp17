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

             
              

 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    return 0;
}