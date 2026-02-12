#include <iostream>

// Base class template
template <typename Derived>
class Printer
{
public:
    void print()
    {
        // Call derived implementation
        static_cast<Derived *>(this)->printImpl();
    }
};

// Derived class
class HelloPrinter : public Printer<HelloPrinter>
{
public:
    void printImpl()
    {
        std::cout << "Hello from CRTP\n";
    }
};

class HelloPrinter2 : public Printer<HelloPrinter2>
{
public:
    void printImpl()
    {
        std::cout << "Hello from CRTP2\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    HelloPrinter p;
    p.print();

    HelloPrinter2 p2;
    p2.print();
}
