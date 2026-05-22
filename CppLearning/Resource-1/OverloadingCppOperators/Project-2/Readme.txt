Rvalue References
    rvalue references, written as && instead of the normal lvalue references, &.
    The normal assignment operator has the following prototype:

        T& operator=(const T&);

    The move assignment operator has almost the same prototype, but uses an rvalue reference. 
    It modifies the argument so it cannot be passed as const.

        T& operator=(T&&);

    The std::string class from the Standard Library, 
    for example, implements an operator+ using rvalue references as follows (simplified)

        string operator+(string&& lhs, string&& rhs);

    both are temporary objects that will be destroyed when this operator+ is finished.
    implementation of the preceding operator+

        return std::move(lhs.append(rhs));
        or
        return std::move(rhs.insert(0, lhs));

    The following is a list of all operator+ operators for std::string accepting two strings as arguments (simplified)

        string operator+(const string& lhs, const string& rhs);
        string operator+(string&& lhs, const string& rhs);
        string operator+(const string& lhs, string&& rhs);
        string operator+(string&& lhs, string&& rhs);

Relational Operators
    There is a handy <utility> header file included with the C++ Standard Library.
    It also contains the following set of function templates for relational operators in the std::rel_ops namespace

        template<class T> bool operator!=(const T& a, const T& b);// Needs operator==
        template<class T> bool operator>(const T& a, const T& b); // Needs operator<
        template<class T> bool operator<=(const T& a, const T& b);// Needs operator<
        template<class T> bool operator>=(const T& a, const T& b);// Needs operator<

    If you implement operator== and operator< in your class, 
    you get the other relational operators for free with these templates.
    adding a #include <utility> and adding the following using statement 
    using namespace std::rel_ops;

    problem 
        those operators might be created for all classes that you use in relational operations, not only for your own class.
        utility templates such as std::greater<T> do not work with those automatically generated relational operators.
        implicit conversions will not work.

    I recommend that you just implement all relational operators for a class yourself instead of relying on std::rel_ops.