#include <iostream>
#include <cstddef>
#include <new>

using namespace std;

namespace example1
{
    class MemoryDemo
    {
    public:
        virtual ~MemoryDemo() = default;

        MemoryDemo()
        {
            cout << "ctor called " << endl;

            /*
                You cannot call operator delete with extra parameters yourself,
                but it will be called only when you use your operator new with extra parameters and
                the constructor of your object throws an exception.
            */
            throw ::runtime_error("test exception");
        }

        void *operator new(size_t size);
        void operator delete(void *ptr) noexcept;

        void *operator new[](size_t size);
        void operator delete[](void *ptr) noexcept;

        void *operator new(size_t size, const std::nothrow_t &) noexcept;
        void operator delete(void *ptr, const std::nothrow_t &) noexcept;

        void *operator new[](size_t size, const std::nothrow_t &) noexcept;
        void operator delete[](void *ptr, const std::nothrow_t &) noexcept;

        // Overloading operator new and operator delete with Extra Parameters
        void *operator new(size_t size, int extra);
        void operator delete(void *ptr, int extra) noexcept;
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

    void *MemoryDemo::operator new(size_t size, int extra)
    {
        cout << "operator new with extra int: " << extra << endl;
        return ::operator new(size);
    }

    void MemoryDemo::operator delete(void *ptr, int extra) noexcept
    {
        cout << "operator delete with extra int: " << extra << endl;
        ::operator delete(ptr);
    }

    void test1()
    {
        try
        {
            MemoryDemo *memp = new (5) MemoryDemo();
            delete memp;
        }
        catch (const std::exception &e)
        {
            std::cerr << "exception: " << e.what() << '\n';
        }
    }
}

namespace example2
{
    class MemoryDemo // default sizeof(MemoryDemo) == 1 byte
    {
    public:
        virtual ~MemoryDemo() = default; // sizeof(MemoryDemo) == 8 byte

        void *operator new(size_t size);
        // Overloading operator delete with Size of Memory as Parameter
        void operator delete(void *ptr, size_t size) noexcept;
    };

    void *MemoryDemo::operator new(size_t size)
    {
        cout << "operator new" << endl;
        return ::operator new(size);
    }

    void MemoryDemo::operator delete(void *ptr, size_t size) noexcept
    {
        cout << "operator delete with size " << size << endl; // in byte
        ::operator delete(ptr);
    }

    void test1()
    {
        MemoryDemo *mem = new MemoryDemo();
        delete mem;

        std::cout << "class MemoryDemo size : " << sizeof(MemoryDemo) << '\n'; // in byte
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //example1::test1();
    example2::test1();

    return 0;
}