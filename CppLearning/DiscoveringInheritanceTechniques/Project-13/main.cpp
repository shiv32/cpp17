/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   INHERITANCE FOR POLYMORPHISM
                Now that you understand the relationship between a derived class and its parent.
                You can use inheritance in its most powerful scenario—polymorphism.

            Return of the Spreadsheet
                A SpreadsheetCell represents a single element of data.
                Up to now, that element always stored a single double value.

                Note that a cell can be set either as a double or a string, but it is always stored as a double.
                The current value of the cell, however, is always returned as a string for this example.

                                class SpreadsheetCell
                                    {
                                        public:
                                            virtual void set(double inDouble);
                                            virtual void set(std::string_view inString);
                                            virtual std::string getString() const;
                                        private:
                                            static std::string doubleToString(double inValue);
                                            static double stringToDouble(std::string_view inString);
                                            double mValue;
                                    };

                In a real spreadsheet application, cells can store different things.
                A cell could store a double, but it might just as well store a piece of text.
                There could also be a need for additional types of cells, such as a formula cell, or a date cell.

            Designing the Polymorphic Spreadsheet Cell
                Narrow the scope of the SpreadsheetCell to cover only strings, 
                perhaps renaming it StringSpreadsheetCell in the process. 
                To handle doubles, a second class, DoubleSpreadsheetCell, would inherit from the StringSpreadsheetCell and
                provide functionality specific to its own format.

                            StringSpreadsheetCell <--- DoubleSpreadsheetCell

                The derived class would override most, if not all, of the functionality of the base class. 
                Because doubles are treated differently from strings in almost all cases. 
                There clearly is a relationship between a cell containing strings and a cell containing doubles.
                Which implies that somehow a DoubleSpreadsheetCell “is-a” StringSpreadsheetCell.

                A better design would make these classes peers with a common parent, SpreadsheetCell.

                                
                                        /---DoubleSpreadsheetCell
                            SpreadsheetCell
                                        \---StringSpreadsheetCell

                It shows a polymorphic approach to the SpreadsheetCell hierarchy.
                Because DoubleSpreadsheetCell and StringSpreadsheetCell both inherit from a common 
                parent, SpreadsheetCell, they are interchangeable in the view of other code. 

                 In practical terms, that means the following:

                    ➤ Both derived classes support the same interface (set of methods) defined by the base class.

                    ➤ Code that makes use of SpreadsheetCell objects can call any method in the interface without 
                    even knowing whether the cell is a DoubleSpreadsheetCell or a StringSpreadsheetCell.
                    
                    ➤ Through the magic of virtual methods, the appropriate instance of every method in the
                    interface is called depending on the class of the object.
                    
                    ➤ Other data structures, can contain a collection of multi-typed cells by referring to the parent type.


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