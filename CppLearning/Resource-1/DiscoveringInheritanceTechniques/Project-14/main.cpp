/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  The SpreadsheetCell Base Class
                When designing a base class, you need to consider how the derived classes relate to each other. 
                From this information, you can derive the commonality that will go inside the parent class.

                    eg. 
                        string cells and double cells are similar in that they both contain a single piece of data. 
                        Because the data is coming from the user and will be displayed back to the user, 
                        the value is set as a string and retrieved as a string. 
                        These behaviors are the shared functionality that will make up the base class.

            A First Attempt
                The SpreadsheetCell base class is responsible for defining the behaviors that all
                SpreadsheetCell-derived classes will support.

                    eg.
                        All cells need to be able to set their value as a string. 
                        All cells also need to be able to return their current value as a string.
                        The base class definition declares these methods, as well as an explicitly defaulted virtual 
                        destructor, but note that it has no data members.

                                    class SpreadsheetCell
                                    {
                                        public:
                                        virtual ~SpreadsheetCell() = default;
                                        virtual void set(std::string_view inString);
                                        virtual std::string getString() const;
                                    };

                        Calling the set() method on the SpreadsheetCell base class will have no effect because the base
                        class has nothing to set. 
                        Ideally, there should never be an object that is an instance of the base class. 
                        Calling set() should always have an effect because it should always be called on either 
                        a DoubleSpreadsheetCell or a StringSpreadsheetCell.
                        A good solution enforces this constraint.

            Pure Virtual Methods and Abstract Base Classes
                Pure virtual methods are methods that are explicitly undefined in the class definition. 
                A class with at least one pure virtual method is said to be an abstract class because no
                other code will be able to instantiate it. 

                There is a special syntax for designating a pure virtual method.
                The method declaration is followed by =0. No implementation needs to be written.

                                    class SpreadsheetCell
                                    {
                                        public:
                                        virtual ~SpreadsheetCell() = default;
                                        virtual void set(std::string_view inString) = 0;
                                        virtual std::string getString() const = 0;
                                    };

            Now that the base class is an abstract class, it is impossible to create a SpreadsheetCell object.

                        SpreadsheetCell cell; // Error! Attempts creating abstract class instance

             Once the StringSpreadsheetCell class has been implemented, 
             the following code will compile fine because it instantiates a derived class of the abstract base class.

                        std::unique_ptr<SpreadsheetCell> cell(new StringSpreadsheetCell());

            NOTE:   An abstract class provides a way to prevent other code from instantiating
                    an object directly, as opposed to one of its derived classes.

            Note that you don’t need a SpreadsheetCell.cpp source file, because there is nothing to implement.
                

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