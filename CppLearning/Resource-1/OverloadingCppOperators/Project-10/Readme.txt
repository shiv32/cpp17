Overloading operator new and operator delete

    If you fail to heed my advice and decide to replace the global operator new, 
    keep in mind that you cannot put any code in the operator that makes a call 
    to new because this will cause an infinite recursion. 
    For example, you cannot write a message to the console with cout.

    Whenever you overload operator new, overload the corresponding form of operator delete. 
    Otherwise, memory will be allocated as you specify but freed according to the built-in semantics, 
    which may not be compatible.

    Overload all forms of operator new, or explicitly delete forms that you don’t want to get used, 
    to prevent inconsistencies in the memory allocations.

