#include <iostream>

struct A
{
    A(const char *name) : name(name)
    {
        std::cout << "Construct " << name << '\n';
    }

    ~A()
    {
        std::cout << "Destruct " << name << '\n';
    }

    const char *name;
};

void func3()
{
    A a3("a3");
    throw std::runtime_error("Error in func3");
}

void func2()
{
    A a2("a2");
    func3(); // exception propagates upward
}

void func1()
{
    A a1("a1");
    func2();
}

int main()
{
    try
    {
        func1();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}
