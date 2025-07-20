#include <iostream>
#include <cstring>

class Person
{
private:
    char *name;

public:
    // 1. Constructor
    Person(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        std::cout << "Constructor\n";
    }

    // 2. Destructor
    ~Person()
    {
        delete[] name;
        std::cout << "Destructor\n";
    }

    // 3. Copy Constructor
    Person(const Person &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        std::cout << "Copy Constructor\n";
    }

    // 4. Copy Assignment Operator
    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }

        std::cout << "Copy Assignment\n";
        return *this;
    }

    // 5. Move Constructor
    Person(Person &&other) noexcept
    {
        name = other.name;
        other.name = nullptr;
        std::cout << "Move Constructor\n";
    }

    // 6. Move Assignment Operator
    Person &operator=(Person &&other) noexcept
    {
        if (this != &other)
        {
            delete[] name;
            name = other.name;
            other.name = nullptr;
        }

        std::cout << "Move Assignment\n";
        return *this;
    }

    void greet() const
    {
        std::cout << "Hello, I am " << (name ? name : "nobody") << "\n";
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
