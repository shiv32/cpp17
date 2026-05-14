Summary of Overloadable Operators
    This table is a useful reference for the future when you want to write an overloaded operator.
    In this table, T is the name of the class for which the overloaded operator is written, and E is a different type. 
    Note that the sample prototypes given are not exhaustive; often there are other combinations of T and E possible for a given operator.

--------------------------------------------------------
1.
OPERATOR	                                         
    operator+
    operator-                              
    operator*
    operator/
    operator%
NAME OR CATEGORY 
    Binary arithmetic
 METHOD OR GLOBAL FUNCTION  
    Global function recommended   
WHEN TO OVERLOAD    
    Whenever you want to provide these operations for your class
 SAMPLE PROTOTYPE
    T operator+(const T&, const T&);
    T operator+(const T&, const E&);
-------------------------------------------------------
2.
OPERATOR
    operator-
    operator+
    operator~
NAME OR CATEGORY 
    Unary arithmetic and bitwise operators
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you want to provide these operations for your class
SAMPLE PROTOTYPE
    T operator-() const;
------------------------------------------------------
3.
OPERATOR
    operator++
    operator--
NAME OR CATEGORY 
    Pre-increment and pre-decrement
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you overload += and -= taking an arithmetic argument (int, long, ...)
SAMPLE PROTOTYPE
    T& operator++();
-------------------------------------------------------
4.
OPERATOR
    operator++
    operator--
NAME OR CATEGORY 
    Post-increment and post-decrement
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you overload += and -= taking an arithmetic argument (int, long, ...)
SAMPLE PROTOTYPE
    T operator++(int);
---------------------------------------------------
5.
OPERATOR
    operator=
NAME OR CATEGORY 
    Assignment operator
METHOD OR GLOBAL FUNCTION 
    Method required
WHEN TO OVERLOAD 
    Whenever your class has dynamically allocated memory or resources, or members that are references
SAMPLE PROTOTYPE
    T& operator=(const T&);
---------------------------------------------------
6.
OPERATOR
    operator+=
    operator-=
    operator*=
    operator/=
    operator%=
NAME OR CATEGORY 
    Shorthand arithmetic operator assignments
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you overload the binary arithmetic operators and your class is not designed to be immutable
SAMPLE PROTOTYPE
    T& operator+=(const T&);
    T& operator+=(const E&);
-------------------------------------------------
7.
OPERATOR
    operator<<
    operator>>
    operator&
    operator|
    operator^
NAME OR CATEGORY 
    Binary bitwise operators
METHOD OR GLOBAL FUNCTION 
    Global function recommended
WHEN TO OVERLOAD 
    Whenever you want to provide these operations
SAMPLE PROTOTYPE
    T operator<<(const T&, const T&);
    T operator<<(const T&, const E&);
------------------------------------------------
8.
OPERATOR
    operator<<=
    operator>>=
    operator&=
    operator|=
    operator^=
NAME OR CATEGORY 
    Shorthand bitwise operator assignments
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you overload the binary bitwise operators and your class is not designed to be immutable
SAMPLE PROTOTYPE
    T& operator<<=(const T&);
    T& operator<<=(const E&);
------------------------------------------------
9.
OPERATOR
    operator<
    operator>
    operator<=
    operator>=
    operator==
    operator!=
NAME OR CATEGORY 
    Binary comparison operators
METHOD OR GLOBAL FUNCTION 
    Global function recommended
WHEN TO OVERLOAD 
    Whenever you want to provide these operations
SAMPLE PROTOTYPE
    bool operator<(const T&, const T&);
    bool operator<(const T&, const E&);
------------------------------------------------
10.
OPERATOR
    operator<<
    operator>>
NAME OR CATEGORY 
    I/O stream operators (insertion and extraction)
METHOD OR GLOBAL FUNCTION 
    Global function required
WHEN TO OVERLOAD 
    Whenever you want to provide these operations
SAMPLE PROTOTYPE
    ostream& operator<<(ostream&, const T&);
    istream& operator>>(istream&, T&);
------------------------------------------------
11.
OPERATOR
    operator!
NAME OR CATEGORY 
    Boolean negation operator
METHOD OR GLOBAL FUNCTION 
    Member function recommended
WHEN TO OVERLOAD 
    Rarely; use bool or void* conversion instead.
SAMPLE PROTOTYPE
    bool operator!() const;
---------------------------------------------
12.
OPERATOR
    operator&&
    operator||
NAME OR CATEGORY 
    Binary Boolean operators
METHOD OR GLOBAL FUNCTION 
    Global function recommended
WHEN TO OVERLOAD 
    Rarely, if ever, because you lose short-circuiting; 
    it’s better to overload & and | instead, as these never short-circuit.
SAMPLE PROTOTYPE
    bool operator&&(const T&, const T&);
--------------------------------------------
13.
OPERATOR
    operator[]
NAME OR CATEGORY 
    Subscripting (array index) operator
METHOD OR GLOBAL FUNCTION 
    Method required
WHEN TO OVERLOAD 
    When you want to support subscripting
SAMPLE PROTOTYPE
    E& operator[](size_t);
    const E& operator[](size_t) const;
---------------------------------------------
14.
OPERATOR
    operator()
NAME OR CATEGORY 
    Function call operator
METHOD OR GLOBAL FUNCTION 
    Method required
WHEN TO OVERLOAD 
    When you want objects to behave like function pointers, 
    or for multi-dimensional array access, since [] can only have one index
SAMPLE PROTOTYPE
    Return type and parameters can vary; see examples.
----------------------------------------------
15.
OPERATOR
    operator type()
NAME OR CATEGORY 
    Conversion, or cast, operators (separate operator for each type)
METHOD OR GLOBAL FUNCTION 
    Method required
WHEN TO OVERLOAD 
    When you want to provide conversions from your class to other types
SAMPLE PROTOTYPE
    operator double() const;
----------------------------------------------
16.
OPERATOR
    operator new
    operator new[]
NAME OR CATEGORY 
    Memory allocation routines
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    When you want to control memory allocation for your classes (rarely)
SAMPLE PROTOTYPE
    void* operator new(size_t size);
    void* operator new[](size_t size);
---------------------------------------------
17.
OPERATOR
    operator delete
    operator delete[]
NAME OR CATEGORY 
    Memory deallocation routines
METHOD OR GLOBAL FUNCTION 
    Method recommended
WHEN TO OVERLOAD 
    Whenever you overload the memory allocation routines (rarely)
SAMPLE PROTOTYPE
    void operator delete(void* ptr) noexcept;
    void operator delete[](void* ptr) noexcept;
--------------------------------------------
18.
OPERATOR
    operator*
    operator->
NAME OR CATEGORY 
    Dereferencing operators
METHOD OR GLOBAL FUNCTION 
    Method recommended for operator*
    Method required for operator->
WHEN TO OVERLOAD 
    Useful for smart pointers
SAMPLE PROTOTYPE
    E& operator*() const;
    E* operator->() const;
--------------------------------------------
19.
OPERATOR
    operator&
NAME OR CATEGORY 
    Address-of operator
METHOD OR GLOBAL FUNCTION 
    N/A
WHEN TO OVERLOAD 
    Never
SAMPLE PROTOTYPE
    N/A
-----------------------------------------------
20.
OPERATOR
    operator->*
NAME OR CATEGORY 
    Dereference pointer-to-member
METHOD OR GLOBAL FUNCTION 
    N/A
WHEN TO OVERLOAD 
    Never
SAMPLE PROTOTYPE
    N/A
-----------------------------------------------
21.
OPERATOR
    operator,
NAME OR CATEGORY 
    Comma operator
METHOD OR GLOBAL FUNCTION 
    N/A
WHEN TO OVERLOAD 
    Never
SAMPLE PROTOTYPE
    N/A
------------------------------------------------