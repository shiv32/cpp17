/**
 * @file RoundRobin.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdexcept>     //throw std::out_of_range

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
    // If the client gave a guideline, reserve that much space.
    mElements.reserve(numExpected);

    // Initialize mCurrentElement even though it isn't used until
    // there's at least one element.
    mCurrentElement = begin(mElements);
}

template <typename T>
void RoundRobin<T>::add(const T &element)
{
    // Even though we add the element at the end, the vector could
    // reallocate and invalidate the mCurrentElement iterator with
    // the push_back() call. Take advantage of the random-access
    // iterator features to save our spot.
    int pos = mCurrentElement - begin(mElements);

    // Add the element.
    mElements.push_back(element);

    // Reset our iterator to make sure it is valid.
    mCurrentElement = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T &element)
{
    for (auto it = begin(mElements); it != end(mElements); ++it)
    {
        if (*it == element)
        {
            // Removing an element invalidates the mCurrentElement iterator
            // if it refers to an element past the point of the removal.
            // Take advantage of the random-access features of the iterator
            // to track the position of the current element after removal.
            int newPos;

            if (mCurrentElement == end(mElements) - 1 && mCurrentElement == it)
            {
                // mCurrentElement refers to the last element in the list,
                // and we are removing that last element, so wrap back to
                // the beginning.
                newPos = 0;
            }
            else if (mCurrentElement <= it)
            {
                // Otherwise, if mCurrentElement is before or at the one
                // we're removing, the new position is the same as before.
                newPos = mCurrentElement - begin(mElements);
            }
            else
            {
                // Otherwise, it's one less than before.
                newPos = mCurrentElement - begin(mElements) - 1;
            }

            // Erase the element (and ignore the return value).
            mElements.erase(it);

            // Now reset our iterator to make sure it is valid.
            mCurrentElement = begin(mElements) + newPos;

            return;
        }
    }
}

template <typename T>
T &RoundRobin<T>::getNext()
{
    // First, make sure there are elements.
    if (mElements.empty())
    {
        throw std::out_of_range("No elements in the list");
    }

    // Store the current element which we need to return.
    auto &toReturn = *mCurrentElement;

    // Increment the iterator modulo the number of elements.
    ++mCurrentElement;

    if (mCurrentElement == end(mElements))
    {
        mCurrentElement = begin(mElements);
    }

    // Return a reference to the element.
    return toReturn;
}
