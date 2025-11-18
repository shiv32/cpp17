#include <iostream>

// C++14 -------------------------------------------------------------
template <typename T1, typename T2>
auto add(const T1 &t1, const T2 &t2)
{
    return t1 + t2;
}

template <typename T1, typename T2>
decltype(auto) add2(const T1 &t1, const T2 &t2)
{
    return t1 + t2;
}

// Before C++14 -------------------------------------------------------
/*
This is wrong.
You are using t1 and t2 in the beginning of the prototype line,
but these are not yet known.

template <typename T1, typename T2>
decltype(t1 + t2) add3(const T1 &t1, const T2 &t2)
{
    return t1 + t2;
}
*/
// alternative function syntax
template <typename T1, typename T2>
auto add4(const T1 &t1, const T2 &t2) -> decltype(t1 + t2)//trailing return type
{
    return t1 + t2;
}

// non-template example ------------------------------------
const std::string message = "Test";

const std::string &getString()
{
    return message;
}