#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
    std::unique_ptr<std::string> name;

public:
    // 1. Constructor
    Person(const std::string &n)
        : name(std::make_unique<std::string>(n))
    {
        std::cout << "Constructor\n";
    }

    // 2. Copy Constructor (Deep Copy)
    Person(const Person &other)
        : name(std::make_unique<std::string>(*other.name))
    {
        std::cout << "Copy Constructor\n";
    }

    // 3. Copy Assignment Operator (Deep Copy)
    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            name = std::make_unique<std::string>(*other.name);
        }
        std::cout << "Copy Assignment\n";
        return *this;
    }

    // 4. Move Constructor
    Person(Person &&other) noexcept = default;

    // 5. Move Assignment Operator
    Person &operator=(Person &&other) noexcept = default;

    void greet() const
    {
        std::cout << "Hello, I am " << *name << "\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Person a("Alice");

    Person b = a;            // Copy constructor
    Person c = std::move(a); // Move constructor

    Person d("David");

    d = b;            // Copy assignment
    d = std::move(c); // Move assignment

    d.greet();

    return 0;
}
