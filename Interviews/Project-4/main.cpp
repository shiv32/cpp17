/**
 * Prototype Design Pattern Example
 */

#include <iostream>
#include <cstring>
#include <memory>

// Prototype interface
class Prototype
{
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
};

// Concrete class that holds a raw pointer
class Data : public Prototype
{
    char *buffer;

public:
    Data(const char *text)
    {
        buffer = new char[strlen(text) + 1];
        std::strcpy(buffer, text);
    }

    // Shallow copy constructor (just copies pointer)
    Data(const Data &other, bool shallow)
    {
        if (shallow)
        {
            buffer = other.buffer; // shared pointer!
        }
        else//deep copy
        {
            buffer = new char[strlen(other.buffer) + 1];
            std::strcpy(buffer, other.buffer);
        }
    }

    // Deep copy by default in clone()
    std::unique_ptr<Prototype> clone() const override
    {
        return std::make_unique<Data>(*this, false); // deep copy
    }

    void print() const override
    {
        std::cout << buffer << "\n";
    }

    ~Data() 
    { 
        delete[] buffer; 
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Data original("Hello Prototype");

    // 1. Shallow copy
    Data shallowCopy(original, true);

    // 2. Deep copy via clone()
    auto deepCopy = original.clone();

    std::cout << "Original: ";
    original.print();

    std::cout << "Shallow:  ";
    shallowCopy.print();
    
    std::cout << "Deep:     ";
    deepCopy->print();

    // If we delete original, shallowCopy will point to freed memory (dangling)
}
