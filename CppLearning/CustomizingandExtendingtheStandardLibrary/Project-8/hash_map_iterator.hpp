#pragma once
#include <cstddef> //size_t

template <typename HashMap>
class hash_map_iterator : public const_hash_map_iterator<HashMap>
{
public:
    using value_type = typename const_hash_map_iterator<HashMap>::value_type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using pointer = value_type *;
    using reference = value_type &;
    using list_iterator_type = typename HashMap::ListType::iterator;

    hash_map_iterator() = default;
    hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap *hashmap);

    value_type &operator*();
    value_type *operator->();

    hash_map_iterator<HashMap> &operator++();
    hash_map_iterator<HashMap> operator++(int);

    hash_map_iterator<HashMap> &operator--();
    hash_map_iterator<HashMap> operator--(int);
};

template <typename HashMap>
hash_map_iterator<HashMap>::hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap *hashmap)
    : const_hash_map_iterator<HashMap>(bucket, listIt, hashmap)
{
}

// Return a reference to the actual element.
template <typename HashMap>
typename hash_map_iterator<HashMap>::value_type &hash_map_iterator<HashMap>::operator*()
{
    return const_cast<value_type &>(*this->mListIterator);
}

// Return a pointer to the actual element, so the compiler can
// apply -> to it to access the actual desired field.
template <typename HashMap>
typename hash_map_iterator<HashMap>::value_type *hash_map_iterator<HashMap>::operator->()
{
    return const_cast<value_type *>(&(*this->mListIterator));
}

// Defer the details to the increment() helper in the base class.
template <typename HashMap>
hash_map_iterator<HashMap> &hash_map_iterator<HashMap>::operator++()
{
    this->increment();
    return *this;
}

// Defer the details to the increment() helper in the base class.
template <typename HashMap>
hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator++(int)
{
    auto oldIt = *this;
    this->increment();
    return oldIt;
}

// Defer the details to the decrement() helper in the base class.
template <typename HashMap>
hash_map_iterator<HashMap> &hash_map_iterator<HashMap>::operator--()
{
    this->decrement();
    return *this;
}

// Defer the details to the decrement() helper in the base class.
template <typename HashMap>
hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator--(int)
{
    auto oldIt = *this;
    this->decrement();
    return oldIt;
}