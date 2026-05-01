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

        // hash_map Emplace Operations
        template <typename... Args>
        std::pair<iterator, bool> emplace(Args &&...args);

        template <typename... Args>
        iterator emplace_hint(const_iterator hint, Args &&...args);

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

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t> hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type &k)
    {
        // Hash the key to get the bucket.
        size_t bucket = mHash(k) % mBuckets.size();

        // Search for the key in the bucket.
        auto iter = find_if(std::begin(mBuckets[bucket]), std::end(mBuckets[bucket]), [this, &k](const auto &element)
                            { return mEqual(element.first, k); });

        // Return a pair of the iterator and the bucket index.
        return std::make_pair(iter, bucket);
    }

    // Construct mBuckets with the correct number of buckets.
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash>::hash_map(const KeyEqual &equal, size_t numBuckets, const Hash &hash)
        : mBuckets(numBuckets), mEqual(equal), mHash(hash)
    {
        if (numBuckets == 0)
        {
            throw std::invalid_argument("Number of buckets must be positive");
        }
    }

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

    // hash_map Initializer List Assignment Operator
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash> &hash_map<Key, T, KeyEqual, Hash>::operator=(std::initializer_list<value_type> il)
    {
        // Do all the work in a temporary instance
        hash_map_type newHashMap(il, mEqual, mBuckets.size(), mHash);
        swap(newHashMap); // Commit the work with only non-throwing operations
        return *this;
    }

    // hash_map Insertion Operations
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<typename hash_map<Key, T, KeyEqual, Hash>::iterator, bool> hash_map<Key, T, KeyEqual, Hash>::insert(const value_type &x)
    {
        // Try to find the element.
        auto [it, bucket] = findElement(x.first);
        bool inserted = false;
        if (it == std::end(mBuckets[bucket]))
        {
            // We didn't find the element, so insert a new one.
            it = mBuckets[bucket].insert(it, x);
            inserted = true;
            mSize++;
        }

        return std::make_pair(hash_map_iterator<hash_map_type>(bucket, it, this), inserted);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::insert(const_iterator /*hint*/, const value_type &x)
    {
        // Completely ignore position.
        return insert(x).first;
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    template <typename InputIterator>
    void hash_map<Key, T, KeyEqual, Hash>::insert(InputIterator first, InputIterator last)
    {
        // Copy each element in the range by using an insert_iterator adaptor.
        // Give begin() as a dummy position -- insert ignores it anyway.
        std::insert_iterator<hash_map_type> inserter(*this, begin());
        std::copy(first, last, inserter);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::insert(std::initializer_list<value_type> il)
    {
        insert(std::begin(il), std::end(il));
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::begin()
    {
        if (mSize == 0)
        {
            // Special case: there are no elements, so return the end iterator.
            return end();
        }

        // We know there is at least one element. Find the first element.
        for (size_t i = 0; i < mBuckets.size(); ++i)
        {
            if (!mBuckets[i].empty())
            {
                return hash_map_iterator<hash_map_type>(i, std::begin(mBuckets[i]), this);
            }
        }

        // Should never reach here, but if we do, return the end iterator.
        return end();
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::end()
    {
        // The end iterator is the end iterator of the list of the last bucket.
        size_t bucket = mBuckets.size() - 1;
        return hash_map_iterator<hash_map_type>(bucket, std::end(mBuckets[bucket]), this);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::begin() const
    {
        // use const_cast to call the non-const versions.
        return const_cast<hash_map_type *>(this)->begin();
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::end() const
    {
        // use const_cast to call the non-const versions.
        return const_cast<hash_map_type *>(this)->end();
    }

    // The cbegin() and cend() methods forward the request to the const versions of begin() and end()
    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::cbegin() const
    {
        return begin();
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::const_iterator hash_map<Key, T, KeyEqual, Hash>::cend() const
    {
        return end();
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::swap(hash_map<Key, T, KeyEqual, Hash> &other) noexcept
    {
        using std::swap;

        swap(mBuckets, other.mBuckets);
        swap(mSize, other.mSize);
        swap(mEqual, other.mEqual);
        swap(mHash, other.mHash);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::size_type hash_map<Key, T, KeyEqual, Hash>::erase(const key_type &k)
    {
        // First, try to find the element.
        auto [it, bucket] = findElement(k);
        if (it != std::end(mBuckets[bucket]))
        {
            // The element exists -- erase it.
            mBuckets[bucket].erase(it);
            mSize--;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::erase(iterator position)
    {
        iterator next = position;
        ++next;
        // Erase the element from its bucket.
        mBuckets[position.mBucketIndex].erase(position.mListIterator);
        mSize--;
        return next;
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::iterator hash_map<Key, T, KeyEqual, Hash>::erase(iterator first, iterator last)
    {
        // Erase all the elements in the range.
        for (iterator next = first; next != last;)
        {
            next = erase(next);
        }
        return last;
    }
}