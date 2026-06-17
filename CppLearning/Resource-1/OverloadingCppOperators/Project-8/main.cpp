#include <iostream>
#include "SpreadsheetCell.hpp"

using namespace std;

namespace example1
{
    void test1()
    {
        SpreadsheetCell cell(1.23);

        // double d1 = cell; // DOES NOT COMPILE!, Works as expected after overload double() without explicit
        // double d1 = (double)cell; // STILL DOES NOT COMPILE!, Works as expected after overload double() without explicit

        // cout << "d1: " << d1 << endl;

        string str = cell; // Works as expected after overload string() without explicit
        cout << "str: " << str << endl;
    }

    void test2()
    {
        SpreadsheetCell cell(1.23);

        double d2 = cell + 3.3; // DOES NOT COMPILE IF YOU DEFINE operator double() (It works with/without explicit as per test)

        // cout << "d2: " << d2 << endl;
    }

    void test3()
    {
        SpreadsheetCell cell = 6.6;

        string str = cell;
        double d1 = static_cast<double>(cell);
        double d2 = static_cast<double>(cell + 3.3); // need operator+(const SpreadsheetCell &c, double d);
        // double d2 = static_cast<double>(cell) + 3.3;
        double d3 = static_cast<double>(3.3 + cell); // operator+(double d, const SpreadsheetCell &c);

        cout << "str: " << str << endl;
        cout << "d1: " << d1 << endl;
        cout << "d2: " << d2 << endl;
        cout << "d3: " << d3 << endl;
    }

}

namespace example2
{
    template <typename T>
    class Pointer
    {
    public:
        Pointer(T *ptr);
        virtual ~Pointer();

        // Prevent assignment and pass by value.
        Pointer(const Pointer<T> &src) = delete;
        Pointer<T> &operator=(const Pointer<T> &rhs) = delete;

        // Dereferencing operators will go here.
        // OVERLOADING THE DEREFERENCING OPERATORS
        T &operator*();
        const T &operator*() const;
        T *operator->();
        const T *operator->() const;

        //--------------------------------------------
        // The usual pointer type for the conversion operator is void*
        // because that’s a pointer type with which you cannot do much except test it in Boolean expressions.
        // operator void *() const; //many programmers prefer operator void*() instead of operator bool().

        operator bool() const; // alternative of void*

        template <typename P>
        friend bool operator!=(const Pointer<P> &lhs, std::nullptr_t rhs); // nullptr has its own type called nullptr_t
        //-------------------------------------------

    private:
        T *mPtr = nullptr;
    };

    template <typename T>
    Pointer<T>::Pointer(T *ptr) : mPtr(ptr)
    {
    }

    template <typename T>
    Pointer<T>::~Pointer()
    {
        delete mPtr;
        mPtr = nullptr;
    }

    template <typename T>
    T &Pointer<T>::operator*()
    {
        // return *mPtr;
        return const_cast<T &>(as_const(*this).operator*());
    }

    template <typename T>
    const T &Pointer<T>::operator*() const
    {
        return *mPtr;
    }

    template <typename T>
    T *Pointer<T>::operator->()
    {
        // return mPtr;
        return const_cast<T *>(as_const(*this).operator->());
    }

    template <typename T>
    const T *Pointer<T>::operator->() const
    {
        return mPtr;
    }

    // template <typename T>
    // Pointer<T>::operator void *() const
    // {
    //     return mPtr;
    // }

    template <typename T>
    Pointer<T>::operator bool() const
    {
        return mPtr != nullptr;
    }

    template <typename P>
    bool operator!=(const Pointer<P> &lhs, std::nullptr_t rhs)
    {
        return lhs.mPtr != rhs;
    }

    // Conversions for Boolean Expressions
    void process(Pointer<SpreadsheetCell> &p)
    {
        // with operator bool(), results in a compilation error,
        // solution impement operator!=(const Pointer<T>& lhs, std::nullptr_t rhs)
        if (p != nullptr)
        {
            cout << "not nullptr" << endl;
        }

        // after implementing this operator!=, comparison stops working (but as per test it work)
        if (p != NULL)
        {
            cout << "not NULL" << endl;
        }

        if (p)
        {
            cout << "not nullptr" << endl;
        }

        if (!p)
        {
            cout << "nullptr" << endl;
        }
    }

    void test1()
    {
        Pointer<SpreadsheetCell> smartCell(nullptr);
        process(smartCell);
        cout << endl;

        Pointer<SpreadsheetCell> anotherSmartCell(new SpreadsheetCell(5.0));
        process(anotherSmartCell);

        // with the operator bool(), the following code compiles and runs
        int i = anotherSmartCell; // Converts Pointer to bool to int, That’s usually not behavior that you expect or desire.
        cout << "i: " << i << endl;

        int i2 = smartCell; // Converts Pointer to bool to int, That’s usually not behavior that you expect or desire.
        cout << "i2: " << i2 << endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // example1::test1();
    // example1::test2();
    // example1::test3();

    example2::test1();

    return 0;
}