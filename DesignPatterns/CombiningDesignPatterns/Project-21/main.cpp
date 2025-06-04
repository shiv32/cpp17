#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

// SensorReading struct
struct SensorReading
{
    float temperature;
    float humidity;
    std::string timestamp;

    SensorReading() : temperature(0), humidity(0), timestamp("N/A") {} //Default constructor

    SensorReading(float t, float h) : temperature(t), humidity(h)
    {
        auto now = std::chrono::system_clock::now();
        auto in_time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time), "%F %T");
        timestamp = ss.str();
    }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &sr)
    {
        os << "[Temp: " << sr.temperature << "°C, Humidity: " << sr.humidity
           << "%, Time: " << sr.timestamp << "]";
        return os;
    }
};

// Strategy Pattern: LRU Eviction
template <typename K>
class IEvictionPolicy
{
public:
    virtual void keyAccessed(const K &key) = 0;
    virtual K evictKey() = 0;
    virtual ~IEvictionPolicy() = default;
};

template <typename K>
class LRUEviction : public IEvictionPolicy<K>
{
    std::list<K> accessOrder;
    std::unordered_map<K, typename std::list<K>::iterator> map;

public:
    void keyAccessed(const K &key) override
    {
        if (map.find(key) != map.end())
        {
            accessOrder.erase(map[key]);
        }
        accessOrder.push_front(key);
        map[key] = accessOrder.begin();
    }

    K evictKey() override
    {
        K key = accessOrder.back();
        accessOrder.pop_back();
        map.erase(key);
        return key;
    }
};

// Cache Interface
template <typename K, typename V>
class ICache
{
public:
    virtual void put(const K &key, const V &value) = 0;
    virtual V get(const K &key) = 0;
    virtual ~ICache() = default;
};

// Decorator for Logging
template <typename K, typename V>
class LoggingCache : public ICache<K, V>
{
    std::shared_ptr<ICache<K, V>> wrapped;

public:
    LoggingCache(std::shared_ptr<ICache<K, V>> inner) : wrapped(inner) {}

    void put(const K &key, const V &value) override
    {
        std::cout << "[PUT] Sensor ID: " << key << " => " << value << "\n";
        wrapped->put(key, value);
    }

    V get(const K &key) override
    {
        try
        {
            V val = wrapped->get(key);
            std::cout << "[GET HIT] Sensor ID: " << key << " => " << val << "\n";
            return val;
        }
        catch (...)
        {
            std::cout << "[GET MISS] Sensor ID: " << key << "\n";
            throw;
        }
    }
};

// Cache with Eviction Policy
template <typename K, typename V>
class Cache : public ICache<K, V>
{
    size_t capacity;
    std::unordered_map<K, V> store;
    std::shared_ptr<IEvictionPolicy<K>> evictionPolicy;

public:
    Cache(size_t cap, std::shared_ptr<IEvictionPolicy<K>> policy)
        : capacity(cap), evictionPolicy(policy) {}

    void put(const K &key, const V &value) override
    {
        if (store.size() >= capacity)
        {
            K evict = evictionPolicy->evictKey();
            store.erase(evict);
        }
        store[key] = value;
        evictionPolicy->keyAccessed(key);
    }

    V get(const K &key) override
    {
        if (store.find(key) == store.end())
            throw std::runtime_error("Key not found");
        evictionPolicy->keyAccessed(key);
        return store[key];
    }
};

// Factory for cache creation
template <typename K, typename V>
class CacheFactory
{
public:
    static std::shared_ptr<ICache<K, V>> createLRUCache(size_t size)
    {
        auto core = std::make_shared<Cache<K, V>>(size, std::make_shared<LRUEviction<K>>());
        return std::make_shared<LoggingCache<K, V>>(core);
    }
};

// Main: Simulate sensor readings
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto cache = CacheFactory<int, SensorReading>::createLRUCache(3);

    cache->put(101, SensorReading(22.5f, 55.2f));
    cache->put(102, SensorReading(23.1f, 54.8f));
    cache->put(103, SensorReading(21.9f, 53.0f));
    cache->get(101);                              // Access to refresh LRU
    cache->put(104, SensorReading(24.0f, 50.0f)); // Evicts 102

    try
    {
        cache->get(102);
    }
    catch (...)
    {
    } // MISS

    cache->get(103);
    cache->get(104);

    return 0;
}
