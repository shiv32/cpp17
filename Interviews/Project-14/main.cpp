#include <iostream>

class Data
{
    int *ptr;

public:
    Data(int value) : ptr(new int(value)) {}

    ~Data() { delete ptr; }

    Data(const Data &other) : ptr(new int(*other.ptr)) {}

    // Missing self-assignment check!
    Data &operator=(const Data &other)
    {

        // if (this == &other) // self-assignment check
        //         return *this;

        delete ptr; // deletes own data

        ptr = new int(*other.ptr); // uses other's data (dangling!)

        return *this;
    }

    void show() const { std::cout << *ptr << '\n'; }
};

int main()
{

    Data d1(42);

    // d1 = d1; // self-assignment (dangerous)
    d1.operator=(d1);

    d1.show(); // ❌ undefined behavior (dangling pointer)

    //------------------------------------
    // Data d2(20);
    // d2.show();

    // // d2 = d1;
    // d2.operator=(d1);

    // d2.show();
}
