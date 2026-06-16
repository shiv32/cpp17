#include <iostream>
#include "SpreadsheetCell.hpp"
#include <utility> //as_const

using namespace std;

namespace project1
{
    void test1()
    {
        SpreadsheetCell *cell = new SpreadsheetCell;

        (*cell).setValue(50); // Dereference plus member selection
        cell->setValue(50);   // Shorthand arrow dereference and member selection together

        cout << cell->getValue() << endl;
    }
}

namespace project2
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

    void test1()
    {
        Pointer<int> smartInt(new int);
        *smartInt = 51; // Dereference the smart pointer.
        cout << *smartInt << endl;

        Pointer<SpreadsheetCell> smartCell(new SpreadsheetCell);
        // smartCell->setValue(52); // Dereference and member select the set method.
        (smartCell.operator->())->setValue(52); // C++ translates above code line
        cout << smartCell->getValue() << endl;
    }
}

namespace project3
{
    // access class methods and data members through pointers
    void test1()
    {
        SpreadsheetCell myCell;
        myCell.setValue(53);

        // Pointers to Methods and Data Members.
        double (SpreadsheetCell::*methodPtr)() const = &SpreadsheetCell::getValue;

        // Note the use of the .* operator to dereference the method pointer and call the method.
        cout << (myCell.*methodPtr)() << endl;

        SpreadsheetCell *myCell2 = new SpreadsheetCell();
        myCell2->setValue(54);

        // calling methods via pointers when you have a pointer to an object instead of the object itself.
        cout << (myCell2->*methodPtr)() << endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    project1::test1();
    project2::test1();
    project3::test1();

    return 0;
}