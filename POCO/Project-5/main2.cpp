#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Stringifier.h>

#include <iostream>
#include <csignal>

using namespace Poco::Net;
using namespace Poco::JSON;

// ---------------- Handler ----------------
class HealthHandler : public HTTPRequestHandler
{
public:
    void handleRequest(HTTPServerRequest&,
                       HTTPServerResponse& response) override
    {
        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("application/json");

        Object json;
        json.set("status", "UP");
        json.set("service", "poco-microservice");

        std::ostream& out = response.send();
        Stringifier::stringify(json, out);
    }
};

// ---------------- Factory ----------------
class HandlerFactory : public HTTPRequestHandlerFactory
{
public:
    HTTPRequestHandler* createRequestHandler(
        const HTTPServerRequest& request) override
    {
        if (request.getURI() == "/api/health")
            return new HealthHandler;

        return nullptr;
    }
};

// ---------------- Global flag ----------------
volatile std::sig_atomic_t running = 1;

void handleSignal(int)
{
    running = 0;
}

// ---------------- main ----------------
int main()
{
    std::signal(SIGINT, handleSignal);
    ServerSocket socket(8080);
    HTTPServer server(new HandlerFactory,socket,new HTTPServerParams);

    server.start();
    std::cout << "Server started on port 8080\n";

    // Block main thread
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    server.stop();
    std::cout << "Server stopped\n";

    return 0;
}
