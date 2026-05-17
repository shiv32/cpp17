
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/ServerSocket.h>

#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Stringifier.h>

#include <Poco/Dynamic/Var.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/SocketAddress.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <csignal>
#include <atomic>

// ---------------- GLOBAL RUN FLAG ----------------
std::atomic<bool> running(true);

// ---------------- ROUTE MODEL ----------------
struct Route
{
    std::string method;
    std::string path;
    Poco::JSON::Object::Ptr response;
};

std::vector<Route> g_routes;

// ---------------- SIGNAL HANDLER ----------------
void handleSignal(int)
{
    std::cout << "\nStopping server...\n";
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
          "response": { "status": "User Created" }
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

        std::cout << "Incoming: " << req.getMethod()
                  << " " << req.getURI() << "\n";

        // Read body
        std::stringstream ss;
        Poco::StreamCopier::copyStream(req.stream(), ss);
        std::string body = ss.str();

        if (!body.empty())
        {
            std::cout << "Body: " << body << "\n";
        }

        // Route match
        for (auto &route : g_routes)
        {
            if (route.method == req.getMethod() &&
                route.path == req.getURI())
            {

                res.setContentType("application/json");
                std::ostream &out = res.send();
                Poco::JSON::Stringifier::stringify(route.response, out);
                return;
            }
        }

        // 404
        res.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        res.setContentType("application/json");

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

// ---------------- PARSE IP:PORT ----------------
Poco::Net::SocketAddress parseAddress(int argc, char **argv)
{
    std::string addr = "127.0.0.1:8080"; // default

    if (argc > 1)
    {
        addr = argv[1]; // e.g. 127.0.0.1:9000
    }

    return Poco::Net::SocketAddress(addr);
}

// ---------------- MAIN ----------------
int main(int argc, char **argv)
{
    std::signal(SIGINT, handleSignal);

    loadConfig();

    auto socketAddr = parseAddress(argc, argv);

    Poco::Net::ServerSocket socket(socketAddr);

    Poco::Net::HTTPServer server(
        new HandlerFactory(),
        socket,
        new Poco::Net::HTTPServerParams);

    server.start();

    std::cout << "Running at http://" << socketAddr.toString() << "\n";
    std::cout << "Press Ctrl+C to stop\n\n";

    // Keep running
    while (running)
    {
        Poco::Thread::sleep(200);
    }

    server.stop();
    return 0;
}