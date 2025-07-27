/**
 * Prototype Design Pattern Example
 * Safe Smart Pointer Version (No Crash)
 */

#include <iostream>
#include <memory>
#include <cstring>

class Prototype
{
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
};

class Data : public Prototype
{
    std::shared_ptr<char[]> buffer; // shared smart array
public:
    Data(const char *text)
    {
        size_t len = strlen(text) + 1;
        buffer = std::shared_ptr<char[]>(new char[len], std::default_delete<char[]>());
        std::memcpy(buffer.get(), text, len);
    }

    // Shallow copy: shared_ptr just increments refcount
    Data(const Data &other, bool shallow)
    {
        if (shallow)
        {
            buffer = other.buffer;
        }
        else
        {
            size_t len = strlen(other.buffer.get()) + 1;
            buffer = std::shared_ptr<char[]>(new char[len], std::default_delete<char[]>());
            std::memcpy(buffer.get(), other.buffer.get(), len);
        }
    }

    std::unique_ptr<Prototype> clone() const override
    {
        return std::make_unique<Data>(*this, false); // deep copy
    }

    void print() const override { std::cout << buffer.get() << "\n"; }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Data original("Hello Prototype");

    Data shallowCopy(original, true); // shallow copy with shared_ptr is safe
    auto deepCopy = original.clone(); // deep copy

    std::cout << "Original: ";
    original.print();

    std::cout << "Shallow:  ";
    shallowCopy.print();
    
    std::cout << "Deep:     ";
    deepCopy->print();
}
