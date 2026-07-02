#include <iostream>
#include <cstddef>
#include <new>

using namespace std;

namespace example1
{
    /*
        These implementations of operator new and operator delete are
        obviously trivial and not particularly useful.
        They are intended only to give you an idea of the syntax in case
        you ever want to implement nontrivial versions of them.
    */

    class MemoryDemo
    {
    public:
        virtual ~MemoryDemo() = default;

        void *operator new(size_t size);
        void operator delete(void *ptr) noexcept;

        void *operator new[](size_t size);
        void operator delete[](void *ptr) noexcept;

        void *operator new(size_t size, const std::nothrow_t &) noexcept;
        void operator delete(void *ptr, const std::nothrow_t &) noexcept;

        void *operator new[](size_t size, const std::nothrow_t &) noexcept;
        void operator delete[](void *ptr, const std::nothrow_t &) noexcept;
    };

    void *MemoryDemo::operator new(size_t size)
    {
        cout << "operator new" << endl;
        return ::operator new(size);
    }

    void MemoryDemo::operator delete(void *ptr) noexcept
    {
        cout << "operator delete" << endl;
        ::operator delete(ptr);
    }

    void *MemoryDemo::operator new[](size_t size)
    {
        cout << "operator new[]" << endl;
        return ::operator new[](size);
    }

    void MemoryDemo::operator delete[](void *ptr) noexcept
    {
        cout << "operator delete[]" << endl;
        ::operator delete[](ptr);
    }

    void *MemoryDemo::operator new(size_t size, const nothrow_t &nothrow) noexcept
    {
        cout << "operator new nothrow" << endl;
        return ::operator new(size, nothrow);
    }

    void MemoryDemo::operator delete(void *ptr, const nothrow_t &nothrow) noexcept
    {
        cout << "operator delete nothrow" << endl;
        ::operator delete(ptr, nothrow);
    }

    void *MemoryDemo::operator new[](size_t size, const nothrow_t &nothrow) noexcept
    {
        cout << "operator new[] nothrow" << endl;
        return ::operator new[](size, nothrow);
    }

    void MemoryDemo::operator delete[](void *ptr, const nothrow_t &nothrow) noexcept
    {
        cout << "operator delete[] nothrow" << endl;
        ::operator delete[](ptr, nothrow);
    }

    void test1()
    {
        MemoryDemo *mem = new MemoryDemo();
        delete mem;

        mem = new MemoryDemo[10];
        delete[] mem;

        mem = new (nothrow) MemoryDemo();
        delete mem;

        mem = new (nothrow) MemoryDemo[10];
        delete[] mem;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    example1::test1();

    return 0;
}