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

 

 * @version 0.1
 * @date 2024-09-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int main()
{

    return 0;
}