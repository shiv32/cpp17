#include "Bar.hpp"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::displayClassFooData(Foo &fo)
{
    std::cout << "Foo Class data name in Bar class : " << fo.name << std::endl;
}
