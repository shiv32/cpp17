#include <iostream>
#include <string>

class Person
{
private:
    std::string name; // std::string handles memory

public:
    Person(const std::string &n) : name(n) {}

    void greet() const
    {
        std::cout << "Hello, I am " << name << "\n";
    }

    // No destructor, copy/move/assignment needed — all defaulted
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Person a("Alice");

    Person b = a;            // Copy
    Person c = std::move(a); // Move

    b.greet();
    c.greet();

    return 0;
}
