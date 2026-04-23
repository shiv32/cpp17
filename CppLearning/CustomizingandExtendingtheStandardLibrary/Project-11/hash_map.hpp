#pragma once
#include <functional> //std::equal_to<>, std::hash<>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "hash_map_iterator.hpp"

using namespace std;

namespace hm
{
    template <typename Key, typename T, typename KeyEqual = std::equal_to<>, typename Hash = std::hash<Key>>
    class hash_map
    {
    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const Key, T>;
        using hasher = Hash;
        using key_equal = KeyEqual;
        using reference = value_type &;
        using const_reference = const value_type &;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using hash_map_type = hash_map<Key, T, KeyEqual, Hash>;
        using iterator = hash_map_iterator<hash_map_type>;
        using const_iterator = const_hash_map_iterator<hash_map_type>;

    private:
        using ListType = std::list<value_type>;

    public:
        using local_iterator = typename ListType::iterator;
        using const_local_iterator = typename ListType::const_iterator;

        // The iterator classes need access to all members of the hash_map
        friend class hash_map_iterator<hash_map_type>;
        friend class const_hash_map_iterator<hash_map_type>;

        virtual ~hash_map() = default; // Virtual destructor

        // Throws invalid_argument if the number of buckets is illegal.
        explicit hash_map(const KeyEqual &equal = KeyEqual(), size_type numBuckets = 101, const Hash &hash = Hash());

        // Throws invalid_argument if the number of buckets is illegal.
        template <typename InputIterator>
        hash_map(InputIterator first, InputIterator last, const KeyEqual &equal = KeyEqual(), size_type numBuckets = 101, const Hash &hash = Hash());

        // Initializer list constructor
        // Throws invalid_argument if the number of buckets is illegal.
        explicit hash_map(std::initializer_list<value_type> il, const KeyEqual &equal = KeyEqual(), size_type numBuckets = 101, const Hash &hash = Hash());

        // Copy constructor
        hash_map(const hash_map_type &src) = default;
        // Move constructor
        hash_map(hash_map_type &&src) noexcept = default;

        // Copy assignment operator
        hash_map_type &operator=(const hash_map_type &rhs);
        // Move assignment operator
        hash_map_type &operator=(hash_map_type &&rhs) noexcept;
        // Initializer list assignment operator
        hash_map_type &operator=(std::initializer_list<value_type> il);

        // Iterator methods
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        // Size methods
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // Element insert methods
        T &operator[](const key_type &k);
        std::pair<iterator, bool> insert(const value_type &x);
        iterator insert(const_iterator hint, const value_type &x);
        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last);
        void insert(std::initializer_list<value_type> il);

        // Element delete methods
        size_type erase(const key_type &k);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);

        // Other modifying utilities
        void swap(hash_map_type &other) noexcept;
        void clear() noexcept;

        // Access methods for Standard Library conformity
        key_equal key_eq() const;
        hasher hash_function() const;

        // Lookup methods
        iterator find(const key_type &k);
        const_iterator find(const key_type &k) const;
        std::pair<iterator, iterator> equal_range(const key_type &k);
        std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

        size_type count(const key_type &k) const;

    private:
        // Returns a pair containing an iterator to the found element with
        // a given key, and the index of that element's bucket.
        std::pair<typename ListType::iterator, size_t> findElement(const key_type &k);

        std::vector<ListType> mBuckets;
        size_type mSize = 0;
        KeyEqual mEqual;
        Hash mHash;
    };

    // hash_map Iterator Range Constructor
    // Make a call to insert() to actually insert the elements.
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    template <typename InputIterator>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(InputIterator first,
                                               InputIterator last,
                                               const KeyEqual &equal,
                                               size_type numBuckets,
                                               const Hash &hash)
        : hash_map(equal, numBuckets, hash)
    {
        insert(first, last);
    }

    // hash_map Initializer List Constructor
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(std::initializer_list<value_type> il,
                                               const KeyEqual &equal,
                                               size_type numBuckets,
                                               const Hash &hash)
        : hash_map(equal, numBuckets, hash)
    {
        insert(std::begin(il), std::end(il));
    }
}