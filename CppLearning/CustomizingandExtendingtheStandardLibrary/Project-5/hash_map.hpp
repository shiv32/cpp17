#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

namespace hm
{
    template <typename Key, typename T, typename KeyEqual = std::equal_to<>, typename Hash = hash<Key>>
    class hash_map
    {
    public:
        // The Type Aliases
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const Key, T>;

        virtual ~hash_map() = default; // Virtual destructor

        // Throws invalid_argument if the number of buckets is illegal.
        explicit hash_map(const KeyEqual &equal = KeyEqual(), size_t numBuckets = 101, const Hash &hash = Hash());

        // Copy constructor
        hash_map(const hash_map<Key, T, KeyEqual, Hash> &src) = default;

        // Move constructor
        hash_map(hash_map<Key, T, KeyEqual, Hash> &&src) noexcept = default;

        // Copy assignment operator
        hash_map<Key, T, KeyEqual, Hash> &operator=(const hash_map<Key, T, KeyEqual, Hash> &rhs);

        // Move assignment operator
        hash_map<Key, T, KeyEqual, Hash> &operator=(hash_map<Key, T, KeyEqual, Hash> &&rhs) noexcept;

        // Inserts the key/value pair x.
        void insert(const value_type &x);

        // Removes the element with key k, if it exists.
        void erase(const key_type &k);

        // Removes all elements.
        void clear() noexcept;

        // Find returns a pointer to the element with key k.
        // Returns nullptr if no element with that key exists.
        value_type *find(const key_type &k);
        const value_type *find(const key_type &k) const;

        // operator[] finds the element with key k, or inserts an
        // element with that key if none exists yet. Returns a reference to
        // the value corresponding to that key.
        T &operator[](const key_type &k);

        // Swaps two hash_maps.
        void swap(hash_map<Key, T, KeyEqual, Hash> &other) noexcept;

    private:
        using ListType = std::list<value_type>;

        std::vector<ListType> mBuckets;
        // std::vector<std::list<std::pair<const Key, T>>> mBuckets;

        size_t mSize = 0;
        KeyEqual mEqual;
        Hash mHash;

        std::pair<typename ListType::iterator, size_t> findElement(const key_type &k);
    };

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

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t> hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type &k)
    {
        // Hash the key to get the bucket.
        size_t bucket = mHash(k) % mBuckets.size();

        // Search for the key in the bucket.
        auto iter = find_if(begin(mBuckets[bucket]), end(mBuckets[bucket]), [this, &k](const auto &element)
                            { return mEqual(element.first, k); });

        // Return a pair of the iterator and the bucket index.
        return std::make_pair(iter, bucket);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    typename hash_map<Key, T, KeyEqual, Hash>::value_type *hash_map<Key, T, KeyEqual, Hash>::find(const key_type &k)
    {
        // Use the findElement() helper, and C++17 structured bindings.
        auto [it, bucket] = findElement(k);

        if (it == end(mBuckets[bucket]))
        {
            // Element not found -- return nullptr.
            return nullptr;
        }

        // Element found -- return a pointer to it.
        return &(*it);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    const typename hash_map<Key, T, KeyEqual, Hash>::value_type *
    hash_map<Key, T, KeyEqual, Hash>::find(const key_type &k) const
    {
        return const_cast<hash_map<Key, T, KeyEqual, Hash> *>(this)->find(k);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    T &hash_map<Key, T, KeyEqual, Hash>::operator[](const key_type &k)
    {
        // Try to find the element. If it doesn't exist, add a new element.
        auto [it, bucket] = findElement(k);

        if (it == end(mBuckets[bucket]))
        {
            mSize++;
            mBuckets[bucket].push_back(std::make_pair(k, T()));
            return mBuckets[bucket].back().second;
        }
        else
        {
            return it->second;
        }
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::insert(const value_type &x)
    {
        // Try to find the element.
        auto [it, bucket] = findElement(x.first);

        if (it != end(mBuckets[bucket]))
        {
            // The element already exists.
            return;
        }
        else
        {
            // We didn't find the element, so insert a new one.
            mSize++;
            mBuckets[bucket].push_back(x);
        }
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::erase(const key_type &k)
    {
        // First, try to find the element.
        auto [it, bucket] = findElement(k);
        if (it != end(mBuckets[bucket]))
        {
            // The element exists -- erase it.
            mBuckets[bucket].erase(it);
            mSize--;
        }
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    void hash_map<Key, T, KeyEqual, Hash>::clear() noexcept
    {
        // Call clear on each bucket.
        for (auto &bucket : mBuckets)
        {
            bucket.clear();
        }
        mSize = 0;
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
    void swap(hash_map<Key, T, KeyEqual, Hash> &first, hash_map<Key, T, KeyEqual, Hash> &second) noexcept
    {
        first.swap(second);
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash> &hash_map<Key, T, KeyEqual, Hash>::operator=(const hash_map<Key, T, KeyEqual, Hash> &rhs)
    {
        // check for self-assignment
        if (this == &rhs)
        {
            return *this;
        }

        // Copy-and-swap idiom
        auto copy = rhs; // Do all the work in a temporary instance
        swap(copy);      // Commit the work with only non-throwing operations
        return *this;
    }

    template <typename Key, typename T, typename KeyEqual, typename Hash>
    hash_map<Key, T, KeyEqual, Hash> &hash_map<Key, T, KeyEqual, Hash>::operator=(hash_map<Key, T, KeyEqual, Hash> &&rhs) noexcept
    {
        swap(rhs);
        return *this;
    }
}