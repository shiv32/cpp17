#include "MyClass.hpp"

MyClass::MyClass(double value) : mValue(value), mFoo(mValue)
{
    std::cout << "MyClass::mValue = " << mValue << std::endl;
}