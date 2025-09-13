#include <iostream>
#include <cstdint>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

class led_base
{
public:
    virtual void toggle() = 0; // Pure abstract.
    virtual ~led_base() = default;
};

class led_no_toggle : public led_base
{
public:
    led_no_toggle() {}
    virtual ~led_no_toggle() {}

    // Does not have a toggle function.
};

namespace
{
    // led_no_toggle led_no; // Compiler error!
}

//----------------------------------
class Shape
{
protected:
    Shape()
    {
        /* common setup */
        TRACE
    }

public:
    virtual double area() const = 0; // pure virtual
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    Circle(double r) : Shape(), radius(r)
    {
        TRACE
    }

    double area() const override { return 3.14159 * radius * radius; }

private:
    double radius;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //protected ctor of Shape abstract class use case
    // Shape s;       //not allowed
    Circle c(5.0); // allowed; Circle calls Shape() internally

    return 0;
}
