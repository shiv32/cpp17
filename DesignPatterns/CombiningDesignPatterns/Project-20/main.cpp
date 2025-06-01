#include <iostream>
#include <unordered_map>
#include <queue>
#include <memory>
#include <string>

// ---------- EvictionPolicy Interface ----------
template <typename K>
class EvictionPolicy
{
public:
    virtual ~EvictionPolicy() = default;
    virtual void keyAccessed(const K &key) = 0;
    virtual void keyInserted(const K &key) = 0;
    virtual K evictKey() = 0;
};

// ---------- FIFO Eviction Policy ----------
template <typename K>
class FIFOPolicy : public EvictionPolicy<K>
{
    std::queue<K> fifoQueue;

public:
    void keyAccessed(const K &) override
    {
        // FIFO doesn't care on access
    }

    void keyInserted(const K &key) override
    {
        fifoQueue.push(key);
    }

    K evictKey() override
    {
        if (fifoQueue.empty())
            throw std::runtime_error("Eviction requested but queue is empty");
        K key = fifoQueue.front();
        fifoQueue.pop();
        return key;
    }
};

// ---------- Generic Cache ----------
template <typename K, typename V>
class Cache
{
    std::unordered_map<K, V> storage;
    std::shared_ptr<EvictionPolicy<K>> policy;
    size_t capacity;

public:
    Cache(size_t cap, std::shared_ptr<EvictionPolicy<K>> evictor)
        : capacity(cap), policy(std::move(evictor)) {}

    void put(const K &key, const V &value)
    {
        if (storage.size() >= capacity && storage.find(key) == storage.end())
        {
            K evictedKey = policy->evictKey();
            storage.erase(evictedKey);
            std::cout << "[Cache] Evicted key: " << evictedKey << '\n';
        }
        storage[key] = value;
        policy->keyInserted(key);
        std::cout << "[Cache] Inserted key: " << key << ", value: " << value << '\n';
    }

    V get(const K &key)
    {
        if (storage.find(key) == storage.end())
        {
            throw std::runtime_error("Key not found in cache");
        }
        policy->keyAccessed(key);
        std::cout << "[Cache] Accessed key: " << key << '\n';
        return storage[key];
    }

    bool exists(const K &key) const
    {
        return storage.find(key) != storage.end();
    }

    void display() const
    {
        std::cout << "Cache contents:\n";
        for (const auto &pair : storage)
        {
            std::cout << "  " << pair.first << " => " << pair.second << '\n';
        }
    }
};

// ---------- Main Test ----------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto fifo = std::make_shared<FIFOPolicy<std::string>>();

    Cache<std::string, int> myCache(3, fifo);

    myCache.put("A", 1);
    myCache.put("B", 2);
    myCache.put("C", 3);

    myCache.display();

    std::cout << "\nAdding D (should evict A):\n";
    myCache.put("D", 4);

    myCache.display();

    std::cout << "\nAccessing B: " << myCache.get("B") << '\n';

    return 0;
}
