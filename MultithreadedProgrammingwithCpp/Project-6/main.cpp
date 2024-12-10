/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief

        ATOMIC OPERATIONS LIBRARY
        
        g++ main.cpp -o test -latomic && ./test && rm test

 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <atomic>
#include <experimental/type_traits>

using namespace std;

class Foo
{
private:
    int mArray[123];
};

class Bar
{
private:
    int mInt;
    //int mArray[123];
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    atomic<Foo> f;

    // Outputs: 1 0
    cout << std::experimental::fundamentals_v1::is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << endl;

    atomic<Bar> b;

    // Outputs: 1 1
    cout << std::experimental::fundamentals_v1::is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << endl;

    return 0;
}