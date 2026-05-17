#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>

#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Stringifier.h>

#include <Poco/Dynamic/Var.h>
#include <Poco/StreamCopier.h>
#include <Poco/Thread.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <csignal>
#include <atomic>
#include <mutex>

// ---------------- GLOBAL ----------------
std::atomic<bool> running(true);
std::string g_name = "Unknown";
std::mutex g_mutex;

// ---------------- ROUTE ----------------
struct Route
{
    std::string method;
    std::string path;
    std::string action; // NEW
    Poco::JSON::Object::Ptr response;
};

std::vector<Route> g_routes;

// ---------------- SIGNAL ----------------
void handleSignal(int)
{
    std::cout << "\nStopping...\n";
    running = false;
}

// ---------------- LOAD CONFIG ----------------
void loadConfig()
{

    std::string jsonConfig = R"(
    {
      "routes": [
        {
          "method": "GET",
          "path": "/hello",
          "response": { "msg": "Hello World" }
        },
        {
          "method": "POST",
          "path": "/user",
          "action": "SET_NAME"
        },
        {
          "method": "GET",
          "path": "/user",
          "action": "GET_NAME"
        }
      ]
    })";

    Poco::JSON::Parser parser;
    auto result = parser.parse(jsonConfig);
    auto obj = result.extract<Poco::JSON::Object::Ptr>();

    auto routes = obj->getArray("routes");

    for (size_t i = 0; i < routes->size(); ++i)
    {
        auto r = routes->getObject(i);

        Route route;
        route.method = r->getValue<std::string>("method");
        route.path = r->getValue<std::string>("path");

        if (r->has("action"))
            route.action = r->getValue<std::string>("action");

        if (r->has("response"))
            route.response = r->getObject("response");

        g_routes.push_back(route);
    }
}

// ---------------- HANDLER ----------------
class SimulatorHandler : public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &req,
                       Poco::Net::HTTPServerResponse &res) override
    {

        res.setContentType("application/json");

        // read body
        std::stringstream ss;
        Poco::StreamCopier::copyStream(req.stream(), ss);
        std::string body = ss.str();

        Poco::JSON::Object::Ptr requestJson;

        if (!body.empty())
        {
            try
            {
                Poco::JSON::Parser parser;
                auto result = parser.parse(body);
                requestJson = result.extract<Poco::JSON::Object::Ptr>();
            }
            catch (...)
            {
            }
        }

        // route match
        for (auto &route : g_routes)
        {
            if (route.method == req.getMethod() &&
                route.path == req.getURI())
            {

                Poco::JSON::Object response;

                // -------- ACTION: SET NAME --------
                if (route.action == "SET_NAME")
                {
                    if (requestJson && requestJson->has("name"))
                    {
                        std::lock_guard<std::mutex> lock(g_mutex);
                        g_name = requestJson->getValue<std::string>("name");

                        response.set("status", "updated");
                        response.set("name", g_name);
                    }
                    else
                    {
                        response.set("error", "name missing");
                    }
                }

                // -------- ACTION: GET NAME --------
                else if (route.action == "GET_NAME")
                {
                    std::lock_guard<std::mutex> lock(g_mutex);
                    response.set("name", g_name);
                }

                // -------- STATIC RESPONSE --------
                else if (route.response)
                {
                    for (const auto &kv : *route.response)
                    {
                        response.set(kv.first, kv.second);
                    }
                }

                std::ostream &out = res.send();
                Poco::JSON::Stringifier::stringify(response, out);
                return;
            }
        }

        // not found
        res.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        Poco::JSON::Object err;
        err.set("error", "Route not found");

        std::ostream &out = res.send();
        Poco::JSON::Stringifier::stringify(err, out);
    }
};

// ---------------- FACTORY ----------------
class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    Poco::Net::HTTPRequestHandler *createRequestHandler(
        const Poco::Net::HTTPServerRequest &) override
    {
        return new SimulatorHandler();
    }
};

// ---------------- ADDRESS ----------------
Poco::Net::SocketAddress parseAddress(int argc, char **argv)
{
    std::string addr = "127.0.0.1:8080";
    if (argc > 1)
        addr = argv[1];
    return Poco::Net::SocketAddress(addr);
}

// ---------------- MAIN ----------------
int main(int argc, char **argv)
{

    std::signal(SIGINT, handleSignal);

    loadConfig();

    auto addr = parseAddress(argc, argv);
    Poco::Net::ServerSocket socket(addr);

    Poco::Net::HTTPServer server(
        new HandlerFactory(),
        socket,
        new Poco::Net::HTTPServerParams);

    server.start();

    std::cout << "Running at http://" << addr.toString() << "\n";
    std::cout << "POST /user -> set name\n";
    std::cout << "GET  /user -> get name\n";
    std::cout << "Ctrl+C to stop\n";

    while (running)
    {
        Poco::Thread::sleep(200);
    }

    server.stop();
    return 0;
}