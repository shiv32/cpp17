#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/URI.h>
#include <hiredis/hiredis.h>
#include <iostream>
#include <map>

// ======================================================
// Strategy Pattern: Cache Interface
// ======================================================
class ICache
{
public:
    virtual bool exists(const std::string &key) = 0;
    virtual std::string get(const std::string &key) = 0;
    virtual void set(const std::string &key, const std::string &value) = 0;
    virtual ~ICache() = default;
};

// ======================================================
// Redis Implementation
// ======================================================
class RedisCache : public ICache
{
private:
    redisContext *ctx;

public:
    RedisCache()
    {
        ctx = redisConnect("127.0.0.1", 6379);
        if (ctx == nullptr || ctx->err)
        {
            std::cerr << "Redis connection failed\n";
        }
    }

    ~RedisCache()
    {
        if (ctx)
            redisFree(ctx);
    }

    bool exists(const std::string &key) override
    {
        redisReply *reply = (redisReply *)redisCommand(ctx, "EXISTS %s", key.c_str());
        bool res = reply && reply->integer == 1;
        freeReplyObject(reply);
        return res;
    }

    std::string get(const std::string &key) override
    {
        redisReply *reply = (redisReply *)redisCommand(ctx, "GET %s", key.c_str());
        std::string val = (reply && reply->type == REDIS_REPLY_STRING) ? reply->str : "";
        freeReplyObject(reply);
        return val;
    }

    void set(const std::string &key, const std::string &value) override
    {
        redisCommand(ctx, "SET %s %s", key.c_str(), value.c_str());
    }
};

// ======================================================
// Optional: Mock Cache (for testing)
// ======================================================
class RedisMock : public ICache
{
    std::map<std::string, std::string> cache;

public:
    bool exists(const std::string &key) override
    {
        return cache.find(key) != cache.end();
    }

    std::string get(const std::string &key) override
    {
        return cache[key];
    }

    void set(const std::string &key, const std::string &value) override
    {
        cache[key] = value;
    }
};

// ======================================================
// Singleton: Cache Manager
// ======================================================
class CacheManager
{
public:
    static ICache &instance()
    {
        static RedisCache cache;
        // switch easily:
        // static RedisMock cache;
        return cache;
    }
};

// ======================================================
// Service Layer (Business Logic)
// ======================================================
class DataService
{
private:
    ICache &cache;

public:
    DataService(ICache &c) : cache(c)
    {
    }

    std::string getData(const std::string &key)
    {
        if (cache.exists(key))
        {
            return "[CACHE HIT] " + cache.get(key);
        }

        std::string value = "Generated data for key: " + key;
        cache.set(key, value);

        return "[CACHE MISS] " + value;
    }
};

// ======================================================
// HTTP Handler
// ======================================================
class MyHandler : public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override
    {
        Poco::URI uri(request.getURI());
        auto params = uri.getQueryParameters();

        std::string key = "default";

        for (auto &p : params)
        {
            if (p.first == "key")
                key = p.second;
        }

        DataService service(CacheManager::instance());
        std::string result = service.getData(key);

        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        response.setContentType("text/plain");

        std::ostream &out = response.send();
        out << result;
    }
};

// ======================================================
// Factory
// ======================================================
class MyHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &) override
    {
        return new MyHandler();
    }
};

// ======================================================
// Main
// ======================================================
int main()
{
    Poco::Net::ServerSocket socket(8080);
    Poco::Net::HTTPServer server(new MyHandlerFactory(), socket, new Poco::Net::HTTPServerParams);

    server.start();
    std::cout << "Server running on http://localhost:8080\n";

    std::cin.get();
    server.stop();

    return 0;
}

/*
Next upgrade 
Right now:
    ❌ Single Redis connection (not thread-safe)

Next step:
    ✔ Connection pool
    ✔ Async handling
    ✔ TTL (SETEX)
*/