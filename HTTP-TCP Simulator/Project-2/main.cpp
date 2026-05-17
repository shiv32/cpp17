#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>

#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Stringifier.h>

#include <Poco/StreamCopier.h>
#include <Poco/Thread.h>

#include <iostream>
#include <sstream>
#include <csignal>
#include <atomic>
#include <mutex>

// ---------------- GLOBAL STATE ----------------
std::atomic<bool> running(true);

std::string g_name = "Unknown";
std::mutex g_mutex;

// ---------------- SIGNAL HANDLER ----------------
void handleSignal(int)
{
    std::cout << "\nStopping server...\n";
    running = false;
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

        res.setContentType("application/json");

        // ---------------- POST /user ----------------
        if (req.getMethod() == "POST" && req.getURI() == "/user")
        {

            std::stringstream ss;
            Poco::StreamCopier::copyStream(req.stream(), ss);
            std::string body = ss.str();

            Poco::JSON::Object::Ptr json;

            try
            {
                Poco::JSON::Parser parser;
                auto result = parser.parse(body);
                json = result.extract<Poco::JSON::Object::Ptr>();
            }
            catch (...)
            {
            }

            Poco::JSON::Object response;

            if (json && json->has("name"))
            {
                std::lock_guard<std::mutex> lock(g_mutex);
                g_name = json->getValue<std::string>("name");

                response.set("status", "updated");
                response.set("name", g_name);
            }
            else
            {
                response.set("error", "name field missing");
            }

            std::ostream &out = res.send();
            Poco::JSON::Stringifier::stringify(response, out);
            return;
        }

        // ---------------- GET /user ----------------
        if (req.getMethod() == "GET" && req.getURI() == "/user")
        {

            Poco::JSON::Object response;

            {
                std::lock_guard<std::mutex> lock(g_mutex);
                response.set("name", g_name);
            }

            std::ostream &out = res.send();
            Poco::JSON::Stringifier::stringify(response, out);
            return;
        }

        // ---------------- DEFAULT ----------------
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

    auto socketAddr = parseAddress(argc, argv);

    Poco::Net::ServerSocket socket(socketAddr);

    Poco::Net::HTTPServer server(
        new HandlerFactory(),
        socket,
        new Poco::Net::HTTPServerParams);

    server.start();

    std::cout << "Running at http://" << socketAddr.toString() << "\n";
    std::cout << "POST /user  -> set name\n";
    std::cout << "GET  /user  -> get name\n";
    std::cout << "Press Ctrl+C to stop\n\n";

    while (running)
    {
        Poco::Thread::sleep(200);
    }

    server.stop();
    return 0;
}