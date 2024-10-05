// ATOMIC OPERATIONS LIBRARY
// g++ main.cpp -o test -latomic

#include <iostream>
#include <atomic>
#include <experimental/type_traits>

class Foo
{
private:
    int mArray[123];
};

class Bar
{
private:
    int mInt;
};

int main()
{
    using namespace std;

    atomic<Foo> f;

    // Outputs: 1 0
    cout << std::experimental::fundamentals_v1::is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << endl;

    atomic<Bar> b;

    // Outputs: 1 1
    cout << std::experimental::fundamentals_v1::is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << endl;

    return 0;
}