/**
 * @file RoundRobin.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include<vector>

// Class template RoundRobin
// Provides simple round-robin semantics for a list of elements.
template <typename T>
class RoundRobin
{
public:
    // Client can give a hint as to the number of expected elements for
    // increased efficiency.
    RoundRobin(size_t numExpected = 0);
    virtual ~RoundRobin() = default;

    // Prevent assignment and pass-by-value
    RoundRobin(const RoundRobin &src) = delete;
    RoundRobin &operator=(const RoundRobin &rhs) = delete;

    // Explicitly default a move constructor and move assignment operator
    RoundRobin(RoundRobin &&src) = default;
    RoundRobin &operator=(RoundRobin &&rhs) = default;

    // Appends element to the end of the list. May be called
    // between calls to getNext().
    void add(const T &element);

    // Removes the first (and only the first) element
    // in the list that is equal (with operator==) to element.
    // May be called between calls to getNext().
    void remove(const T &element);

    // Returns the next element in the list, starting with the first,
    // and cycling back to the first when the end of the list is
    // reached, taking into account elements that are added or removed.
    T &getNext();

private:
    std::vector<T> mElements;
    typename std::vector<T>::iterator mCurrentElement;
};

//------------------------------ template definition -------------------------
#include "RoundRobin.cpp"


