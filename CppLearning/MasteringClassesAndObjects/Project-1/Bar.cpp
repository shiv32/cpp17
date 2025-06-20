#include "Bar.hpp"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::displayClassFooData(Foo &fo)
{
    std::cout << "Bar class is a friend of Foo class, name : " << fo.name << std::endl;
}
