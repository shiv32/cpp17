/*
Alias Templates

g++ *.cpp -o test
*/

#include <iostream>

template <typename T1, typename T2>
class MyTemplateClass
{
public:
    explicit MyTemplateClass(T1 width, T2 height) : mWidth{width}, mHeight{height}
    {
        std::cout << "mWidth : " << mWidth << std::endl;
        std::cout << "mHeight : " << mHeight << std::endl;
    }

    ~MyTemplateClass() = default;

private:
    T1 mWidth{};
    T2 mHeight{};
};

//---------- Alias Templates -------------------
using MyInt = int; //C++11+
//typedef int MyInt;  //old style

using OtherName = MyTemplateClass<int, double>;

// This is called an alias template.
template <typename T1>
using OtherName2 = MyTemplateClass<T1, double>; //This is something you cannot do with a typedef.

int main()
{
    MyInt val = 5;
    std::cout << "MyInt val : " << val << std::endl;

    std::cout << "--------- ob1 ------------" << std::endl;
    OtherName ob1(3, 5.7);

    std::cout << "--------- ob2 ------------" << std::endl;
    OtherName2<double> ob2(3.3, 7.8);

    return 0;
}