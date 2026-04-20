#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>
#include <iostream>
#include <sstream>
#include <map>
#include <hiredis/hiredis.h>

redisContext *c = redisConnect("127.0.0.1", 6379);

// ---- VERY SIMPLE "FAKE REDIS" (for demo) ----
// Replace with real Redis (hiredis) later
class RedisMock
{
    std::map<std::string, std::string> cache;

public:
    bool exists(const std::string &key)
    {
        return cache.find(key) != cache.end();
    }

    std::string get(const std::string &key)
    {
        return cache[key];
    }

    void set(const std::string &key, const std::string &value)
    {
        cache[key] = value;
    }
};

RedisMock redis;

// ---- Request Handler ----
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

        std::string result;

        // ---- Check Redis (cache) ----
        // if (redis.exists(key))
        // {
        //     result = "[CACHE HIT] " + redis.get(key);
        // }
        // else
        // {
        //     // ---- Simulate backend computation ----
        //     result = "Generated data for key: " + key;

        //     // store in Redis
        //     redis.set(key, result);

        //     result = "[CACHE MISS] " + result;
        // }
        //-------------------------Real redis-------------------------------------------
        redisReply *reply = (redisReply *)redisCommand(c, "GET %s", key.c_str());
        if (reply->type == REDIS_REPLY_STRING)
        {
            result = "[CACHE HIT] " + std::string(reply->str);
        }
        else
        {
            std::string value = "Generated data for key: " + key;

            redisCommand(c, "SET %s %s", key.c_str(), value.c_str());

            result = "[CACHE MISS] " + value;
        }
        freeReplyObject(reply);
        //------------------------------------------------------------------------------

        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        response.setContentType("text/plain");

        std::ostream &out = response.send();
        out << result;
    }
};

// ---- Factory ----
class MyHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &) override
    {
        return new MyHandler();
    }
};

// ---- Main ----
int main()
{
    Poco::Net::ServerSocket socket(8080);
    Poco::Net::HTTPServer server(new MyHandlerFactory(), socket, new Poco::Net::HTTPServerParams);
    server.start();
    std::cout << "C++ POCO Server running on http://localhost:8080\n";

    std::cin.get(); // wait
    server.stop();

    return 0;
}
