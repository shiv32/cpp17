#include <iostream>
#include <string>

class Person
{
    std::string name;
    int age;

public:
    Person(std::string n = "", int a = 0) : name(n), age(a) {}

    // Friend allows access to private data
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    friend std::istream &operator>>(std::istream &is, Person &p);
};

// Output operator <<
std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << ", Age: " << p.age;
    return os; // return stream for chaining
}

// Input operator >>
std::istream &operator>>(std::istream &is, Person &p)
{
    std::cout << "Enter name and age: ";
    is >> p.name >> p.age;
    return is;
}

int main()
{

    Person p1;

    std::cin >> p1; // calls operator>>, operator>>(std::cin, p1);

    std::cout << p1; // calls operator<<, operator<<(std::cout, p1);
}
