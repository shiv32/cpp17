#include "Resource.hpp"

Resource::Resource()
{
    value = 0;
}

void Resource::reset()
{
    value = 0;
}

int Resource::getValue()
{
    return value;
}

void Resource::setValue(int number)
{
    value = number;
}