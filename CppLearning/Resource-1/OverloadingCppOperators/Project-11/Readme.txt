Overloading operator new and operator delete with Extra Parameters
Overloading operator delete with Size of Memory as Parameter
    If your class declares two identical versions of operator delete except that one takes the size parameter and the other doesn’t, 
    the version without the size parameter will always get called. 
    If you want the version with the size parameter to be used, write only that version.


---------------------------------------
See MemoryDemo class in example.

What is sizeof(MemoryDemo)?

The class contains:

    One virtual destructor.
    No data members.

A virtual function causes the compiler to add a virtual table pointer (vptr) to each object.

Typical sizes are:

Architecture	sizeof(void*)	sizeof(MemoryDemo)
32-bit	        4 bytes	        4 bytes
64-bit	        8 bytes	        8 bytes
----------------------------------------
In C++, an empty class is never allowed to have size 0. 

    sizeof(MemoryDemo) == 1

The C++ standard requires that every distinct object has a unique address.

Why is it 1 byte?

If empty classes had size 0:

    MemoryDemo a;
    MemoryDemo b;

then &a and &b would have to be the same address, which is not allowed. 
Giving the class a size of 1 byte ensures that distinct objects have distinct addresses.
-----------------------------------------