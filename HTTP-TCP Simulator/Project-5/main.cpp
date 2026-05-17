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
#include <memory>
#include <unordered_map>

// ---------------- RUN FLAG ----------------
std::atomic<bool> running(true);

void handleSignal(int)
{
    std::cout << "\nStopping...\n";
    running = false;
}

// ---------------- ROUTE ----------------
struct Route
{
    std::string method;
    std::string path;
    std::string action;
    Poco::JSON::Object::Ptr response;
};

// ---------------- FORWARD DECL ----------------
class Context;

// ---------------- COMMAND INTERFACE ----------------
class Command
{
public:
    virtual ~Command() = default;

    virtual Poco::JSON::Object execute(
        Context &ctx,
        Poco::JSON::Object::Ptr requestJson,
        const Route &route) = 0;
};

// ---------------- CONTEXT ----------------
class Context
{
public:
    std::string name = "Unknown";
    std::mutex mtx;

    std::vector<Route> routes;

    std::unordered_map<std::string, std::shared_ptr<Command>> commands;

    std::shared_ptr<Command> getCommand(const Route &route)
    {
        if (!route.action.empty() && commands.count(route.action))
        {
            return commands[route.action];
        }
        return commands["STATIC"];
    }
};

// ---------------- COMMANDS ----------------
class SetNameCommand : public Command
{
public:
    Poco::JSON::Object execute(
        Context &ctx,
        Poco::JSON::Object::Ptr requestJson,
        const Route &) override
    {

        Poco::JSON::Object res;

        if (requestJson && requestJson->has("name"))
        {
            std::lock_guard<std::mutex> lock(ctx.mtx);
            ctx.name = requestJson->getValue<std::string>("name");

            res.set("status", "updated");
            res.set("name", ctx.name);
        }
        else
        {
            res.set("error", "name missing");
        }

        return res;
    }
};

class GetNameCommand : public Command
{
public:
    Poco::JSON::Object execute(
        Context &ctx,
        Poco::JSON::Object::Ptr,
        const Route &) override
    {

        Poco::JSON::Object res;

        std::lock_guard<std::mutex> lock(ctx.mtx);
        res.set("name", ctx.name);

        return res;
    }
};

class StaticCommand : public Command
{
public:
    Poco::JSON::Object execute(
        Context &,
        Poco::JSON::Object::Ptr,
        const Route &route) override
    {

        Poco::JSON::Object res;

        if (route.response)
        {
            for (const auto &kv : *route.response)
            {
                res.set(kv.first, kv.second);
            }
        }

        return res;
    }
};

// ---------------- LOAD CONFIG ----------------
void loadConfig(Context &ctx)
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

        ctx.routes.push_back(route);
    }
}

// ---------------- HANDLER ----------------
class SimulatorHandler : public Poco::Net::HTTPRequestHandler
{
    Context &ctx;

public:
    SimulatorHandler(Context &c) : ctx(c) {}

    void handleRequest(Poco::Net::HTTPServerRequest &req,
                       Poco::Net::HTTPServerResponse &res) override
    {

        res.setContentType("application/json");

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

        for (auto &route : ctx.routes)
        {
            if (route.method == req.getMethod() &&
                route.path == req.getURI())
            {

                auto cmd = ctx.getCommand(route);
                auto response = cmd->execute(ctx, requestJson, route);

                std::ostream &out = res.send();
                Poco::JSON::Stringifier::stringify(response, out);
                return;
            }
        }

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
    Context &ctx;

public:
    HandlerFactory(Context &c) : ctx(c) {}

    Poco::Net::HTTPRequestHandler *createRequestHandler(
        const Poco::Net::HTTPServerRequest &) override
    {
        return new SimulatorHandler(ctx);
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

    Context ctx;

    // register commands
    ctx.commands["SET_NAME"] = std::make_shared<SetNameCommand>();
    ctx.commands["GET_NAME"] = std::make_shared<GetNameCommand>();
    ctx.commands["STATIC"] = std::make_shared<StaticCommand>();

    loadConfig(ctx);

    auto addr = parseAddress(argc, argv);
    Poco::Net::ServerSocket socket(addr);

    Poco::Net::HTTPServer server(
        new HandlerFactory(ctx),
        socket,
        new Poco::Net::HTTPServerParams);

    server.start();

    std::cout << "Running at http://" << addr.toString() << "\n";
    std::cout << "Ctrl+C to stop\n";

    while (running)
    {
        Poco::Thread::sleep(200);
    }

    server.stop();
    return 0;
}