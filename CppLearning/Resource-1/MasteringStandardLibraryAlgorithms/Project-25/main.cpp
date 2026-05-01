/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <utility> //exchange
#include <memory>

#define Log std::cout << __PRETTY_FUNCTION__ << std::endl;

namespace swap
{
    void example1()
    {
        int a = 11;
        int b = 22;

        std::cout << "Before swap(): a = " << a << ", b = " << b << std::endl;

        std::swap(a, b);

        std::cout << "After swap():  a = " << a << ", b = " << b << std::endl;
    }
}

namespace exchange
{
    void example1()
    {
        int a = 11;
        int b = 22;

        std::cout << "Before exchange(): a = " << a << ", b = " << b << std::endl;

        int returnedValue = std::exchange(a, b);

        std::cout << "After exchange():  a = " << a << ", b = " << b << std::endl;
        std::cout << "exchange() returned: " << returnedValue << std::endl;
    }

    class Foo
    {
    public:
        Foo(int *vPtr) : mPtr{vPtr}
        {
        }

        ~Foo()
        {
            Log

            delete mPtr;
            mPtr = nullptr;
        }

        /*
        // move assignment operator
        Foo &operator=(Foo &&rhs) noexcept
        {
            // Check for self-assignment
            if (this == &rhs)
            {
                return *this;
            }

            // Free the old memory
            delete mPtr;
            mPtr = nullptr;

            // Move data
            mPtr = rhs.mPtr;    // Move data from source to destination
            rhs.mPtr = nullptr; // Nullify data in source
            return *this;
        }
        */

        // move assignment operator using exchange
        Foo &operator=(Foo &&rhs) noexcept
        {
            Log

            // Check for self-assignment
            if (this == &rhs)
            {
                return *this;
            }

            // Free the old memory
            delete mPtr;
            mPtr = nullptr;

            // Move data
            mPtr = std::exchange(rhs.mPtr, nullptr); // Move + nullify

            return *this;
        }

        int getValue()
        {
            return *mPtr;
        }

    private:
        int *mPtr;
    };

    void example2()
    {
        Foo foo{new int(32)};
        Foo foo2{new int()};

        foo2 = std::move(foo);//call move assignment operator

        std::cout << foo2.getValue() << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // swap::example1();
    // exchange::example1();
    exchange::example2();

    return 0;
}