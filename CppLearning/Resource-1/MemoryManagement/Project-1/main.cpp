#include <iostream>

using namespace std;

namespace example1
{
    void test1()
    {
        int i = 7; // i is a so-called automatic variable allocated on the stack.

        int *ptr = nullptr; // variable ptr on the stack initialized with nullptr
        ptr = new int;      // When you use the new keyword, memory is allocated on the heap.

        // above code in one-liner
        int *ptr2 = new int; // When you use the new keyword, memory is allocated on the heap.

        // pointers can exist both on the stack and on the heap
        int **handle = nullptr;
        handle = new int *; // stack (handle)
        *handle = new int;  // heap (*handle)
    }

    void leaky()
    {
        new int; // BUG! Orphans/leaks memory!
        cout << "I just leaked an int!" << endl;
    }

    void test2()
    {
        int *ptr = new int;
        delete ptr;
        ptr = nullptr;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 1;
}