#include <iostream>
#include "SpreadsheetCell.hpp"

using namespace std;

namespace example1
{
    void test1()
    {
        SpreadsheetCell *cell = new SpreadsheetCell(); // The part “new SpreadsheetCell()” is called the new-expression.

        delete cell; // This line is called the delete-expression.
    }
}

namespace example2
{
    void *allocateMemorySomehow()
    {
        return nullptr;
    }

    void test1()
    {
        /*
            The New-Expression and operator new

            void* operator new(size_t size);
            void* operator new[](size_t size);
            void* operator new(size_t size, const std::nothrow_t&) noexcept;
            void* operator new[](size_t size, const std::nothrow_t&) noexcept;

            placement new operators, construct an object in preexisting memory

            void* operator new(size_t size, void* p) noexcept;
            void* operator new[](size_t size, void* p) noexcept;
        */

        void *ptr = allocateMemorySomehow();
        SpreadsheetCell *cell = new (ptr) SpreadsheetCell(); // placement new operator
        // do your work using cell then delete cell
        delete cell;
    }

    void test2()
    {
        /*
            The Delete-Expression and operator delete
            C++ standard says that throwing an exception from delete results in undefined behavior.

            void operator delete(void* ptr) noexcept;
            void operator delete[](void* ptr) noexcept;
            void operator delete(void* ptr, const std::nothrow_t&) noexcept;
            void operator delete[](void* ptr, const std::nothrow_t&) noexcept;
            void operator delete(void* p, void*) noexcept;
            void operator delete[](void* p, void*) noexcept;
        */
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}