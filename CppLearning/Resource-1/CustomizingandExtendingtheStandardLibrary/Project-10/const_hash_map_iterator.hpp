#pragma once
#include <cstddef>   //size_t

template <typename HashMap>
class const_hash_map_iterator
{
public:
    using value_type = typename HashMap::value_type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using pointer = value_type *;
    using reference = value_type &;
    using list_iterator_type = typename HashMap::ListType::const_iterator;

    // Bidirectional iterators must supply a default constructor.
    // Using an iterator constructed with the default constructor
    // is undefined, so it doesn't matter how it's initialized.
    const_hash_map_iterator() = default;

    const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap *hashmap);

    // Don't need to define a copy constructor or operator= because the
    // default behavior is what we want.

    // Don't need destructor because the default behavior
    // (not deleting mHashmap) is what we want!

    const value_type &operator*() const;

    // Return type must be something to which -> can be applied.
    // Return a pointer to a pair<const Key, T>, to which the compiler
    // will apply -> again.
    const value_type *operator->() const;

    const_hash_map_iterator<HashMap> &operator++();
    const_hash_map_iterator<HashMap> operator++(int);

    const_hash_map_iterator<HashMap> &operator--();
    const_hash_map_iterator<HashMap> operator--(int);

    // The following are ok as member functions because we don't
    // support comparisons of different types to this one.
    bool operator==(const const_hash_map_iterator<HashMap> &rhs) const;
    bool operator!=(const const_hash_map_iterator<HashMap> &rhs) const;

protected:
    size_t mBucketIndex = 0;
    list_iterator_type mListIterator;
    const HashMap *mHashmap = nullptr;

    // Helper methods for operator++ and operator--
    void increment();
    void decrement();
};

template <typename HashMap>
const_hash_map_iterator<HashMap>::const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap *hashmap)
    : mBucketIndex(bucket), mListIterator(listIt), mHashmap(hashmap)
{
}

// Return a reference to the actual element.
template <typename HashMap>
const typename const_hash_map_iterator<HashMap>::value_type &
const_hash_map_iterator<HashMap>::operator*() const
{
    return *mListIterator;
}

// Return a pointer to the actual element, so the compiler can
// apply -> to it to access the actual desired field.
template <typename HashMap>
const typename const_hash_map_iterator<HashMap>::value_type *
const_hash_map_iterator<HashMap>::operator->() const
{
    return &(*mListIterator);
}

// Defer the details to the increment() helper.
template <typename HashMap>
const_hash_map_iterator<HashMap> &
const_hash_map_iterator<HashMap>::operator++()
{
    increment();
    return *this;
}

// Defer the details to the increment() helper.
template <typename HashMap>
const_hash_map_iterator<HashMap>
const_hash_map_iterator<HashMap>::operator++(int)
{
    auto oldIt = *this;
    increment();
    return oldIt;
}

// Defer the details to the decrement() helper.
template <typename HashMap>
const_hash_map_iterator<HashMap> &
const_hash_map_iterator<HashMap>::operator--()
{
    decrement();
    return *this;
}

// Defer the details to the decrement() helper.
template <typename HashMap>
const_hash_map_iterator<HashMap>
const_hash_map_iterator<HashMap>::operator--(int)
{
    auto oldIt = *this;
    decrement();
    return oldIt;
}

// Behavior is undefined if mListIterator already refers to the past-the-end
// element, or is otherwise invalid.
template <typename HashMap>
void const_hash_map_iterator<HashMap>::increment()
{
    // mListIterator is an iterator into a single bucket. Increment it.
    ++mListIterator;

    // If we're at the end of the current bucket,
    // find the next bucket with elements.
    auto &buckets = mHashmap->mBuckets;
    if (mListIterator == end(buckets[mBucketIndex]))
    {
        for (size_t i = mBucketIndex + 1; i < buckets.size(); i++)
        {
            if (!buckets[i].empty())
            {
                // We found a non-empty bucket.
                // Make mListIterator refer to the first element in it.
                mListIterator = begin(buckets[i]);
                mBucketIndex = i;
                return;
            }
        }

        // No more non-empty buckets. Set mListIterator to refer to the
        // end iterator of the last list.
        mBucketIndex = buckets.size() - 1;
        mListIterator = end(buckets[mBucketIndex]);
    }
}

// Behavior is undefined if mListIterator already refers to the first
// element, or is otherwise invalid.
template <typename HashMap>
void const_hash_map_iterator<HashMap>::decrement()
{
    // mListIterator is an iterator into a single bucket.
    // If it's at the beginning of the current bucket, don't decrement it.
    // Instead, try to find a non-empty bucket before the current one.
    auto &buckets = mHashmap->mBuckets;
    if (mListIterator == begin(buckets[mBucketIndex]))
    {
        for (int i = mBucketIndex - 1; i >= 0; --i)
        {
            if (!buckets[i].empty())
            {
                mListIterator = --end(buckets[i]);
                mBucketIndex = i;
                return;
            }
        }

        // No more non-empty buckets. This is an invalid decrement.
        // Set mListIterator to refer to the end iterator of the last list.
        mBucketIndex = buckets.size() - 1;
        mListIterator = end(buckets[mBucketIndex]);
    }
    else
    {
        // We're not at the beginning of the bucket, so just move down.
        --mListIterator;
    }
}

template <typename HashMap>
bool const_hash_map_iterator<HashMap>::operator==(const const_hash_map_iterator<HashMap> &rhs) const
{
    // All fields, including the hash_map to which the iterators refer,
    // must be equal.
    return (mHashmap == rhs.mHashmap && mBucketIndex == rhs.mBucketIndex && mListIterator == rhs.mListIterator);
}

template <typename HashMap>
bool const_hash_map_iterator<HashMap>::operator!=(const const_hash_map_iterator<HashMap> &rhs) const
{
    return !(*this == rhs);
}