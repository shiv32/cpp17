#include <iostream>

struct A
{
    int x = 0;

    // 1. Default constructor
    A()
    {
        std::cout << "Default\n";
    }

    // 2. Parameterized constructor
    A(int val) : x(val)
    {
        std::cout << "Parameterized: " << x << "\n";
    }

    // 3. Copy constructor
    A(const A& other) : x(other.x)
    {
        std::cout << "Copy: " << x << "\n";
    }

    // 4. Move constructor
    A(A&& other) noexcept : x(other.x)
    {
        other.x = 0;
        std::cout << "Move\n";
    }

    // 5. Delegating constructor
    A(double d) : A(static_cast<int>(d))
    {
        std::cout << "Delegating from double\n";
    }

    // 6. Explicit constructor
    explicit A(char c) : x(c)
    {
        std::cout << "Explicit: " << x << "\n";
    }

    // 7. Bool constructor (manual instead of defaulted)
    //A(bool b)
    explicit A(bool b)
    {
        x = b ? 1 : 0;
        std::cout << "Bool ctor: " << x << "\n";
    }

    // 8. Deleted constructor
    A(std::string) = delete;
    A(const char*) = delete;  // Prevent using string literals

    // 9. constexpr constructor
    constexpr A(float f) : x(static_cast<int>(f)) {}

    // Show value
    void show() const
    {
        std::cout << "Value: " << x << "\n";
    }
};

// 10. Aggregate type (no constructors)
struct B
{
    int x, y;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

     A a1;               // Default
    // A a2(10);           // Parameterized
    // A a3 = a2;          // Copy
    // A a4 = std::move(a2); // Move
    // A a5 = A(5.5);      // Delegating
    // A a6 = A('A');      // Explicit

    //A a7("test");    // Deleted - compile error if uncommented
    //A a7("test");    //allowed: direct initialization, call  A(bool b)
    //A a7 = "test";   //error: copy initialization, not allowed with `explicit`

    //A a8 = A(true);         // Bool

    //  constexpr A a9(3.14f); // constexpr constructor
    //  a9.show();

    // B b1{1, 2};         // Aggregate initialization
    // std::cout << "Aggregate: " << b1.x << ", " << b1.y << "\n";
}
