/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Constructors and Destructors
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <memory>

class Element
{
public:
    Element() {}
    virtual ~Element() = default;
    void setValue(int val)
    {
        value = val;
    }

    int getValue()
    {
        return value;
    }

private:
    int value{-1};
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // The default constructor creates a vector with zero elements.
    std::vector<int> intVector; // Creates a vector of ints with zero elements

    std::cout << "vector of ints with zero elements : ";

    for (auto &element : intVector)
    {
        std::cout << element;
    }
    std::cout << std::endl;

    //-----------------------------------------------------------------------------------
    std::vector<int> intVector2(10, 100); // Creates vector of 10 ints with value 100

    size_t counter = 0;
    std::cout << "vector of 10 ints with value 100 : ";

    for (auto &element : intVector2)
    {
        std::cout << element;

        if (counter != intVector2.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;

    //----------------------------------------------------------------------------------
    // You can create vectors of built-in classes like this:
    std::vector<std::string> stringVector(10, "hello");

    counter = 0;
    std::cout << "vectors of built-in classes : ";

    for (auto &element : stringVector)
    {
        std::cout << element;

        if (counter != stringVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;

    //------------------------------------------------------------------
    // User-defined classes can also be used as vector elements:
    std::vector<Element> elementVector;

    counter = 0;
    std::cout << "User-defined classes in vector : ";

    for (int i = 0; i < 10; ++i)
    {
        Element ele;
        ele.setValue(i * 10);
        elementVector.push_back(ele);
    }

    for (auto &element : elementVector)
    {
        std::cout << element.getValue();

        if (counter != elementVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;
    //----------------------------------------------------------------------------------------
    // A vector can be constructed with an initializer_list containing the initial elements:

    std::vector<int> intVector3({1, 2, 3, 4, 5, 6});

    counter = 0;
    std::cout << "vector with an initializer_list : ";

    for (auto &element : intVector3)
    {
        std::cout << element;

        if (counter != intVector3.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;

    //--------------------------------------------------------------
    // initializer_lists can also be used for so-called uniform initialization

    // std::vector<int> intVector4 = {1, 2, 3, 4, 5, 6};
    std::vector<int> intVector4{1, 2, 3, 4, 5, 6};

    counter = 0;
    std::cout << "vector with an uniform initialization : ";

    for (auto &element : intVector4)
    {
        std::cout << element;

        if (counter != intVector4.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;
    //------------------------------------------------------------
    // You can allocate vectors on the heap as well.

    auto elementVector2 = std::make_unique<std::vector<Element>>(10);

    std::cout << "vectors on the heap : ";

    elementVector2->at(0).setValue(10);
    // std::cout << elementVector2->at(0).getValue();

    (*elementVector2)[1].setValue(20);
    // std::cout << (*elementVector2)[1].getValue();

    elementVector2->at(9).setValue(40);

    for (auto &element : *elementVector2)
    {
        if (element.getValue() == -1)
            element.setValue(30);
    }

    counter = 0;

    for (auto &element : *elementVector2)
    {
        std::cout << element.getValue();

        if (counter != elementVector.size() - 1) // Check if it's not the last element
        {
            std::cout << ", ";
        }

        ++counter; // Increment the counter
    }

    std::cout << std::endl;
    //-------------------------------------------------------------------------

    return 0;
}