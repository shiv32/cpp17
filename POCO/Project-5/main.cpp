
#include <iostream>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Stringifier.h>

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
using namespace Poco::JSON;

// ---------------- Handler ----------------
class HealthHandler : public HTTPRequestHandler
{
public:
    void handleRequest(HTTPServerRequest &request,
                       HTTPServerResponse &response) override
    {
        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("application/json");

        Object json;
        json.set("status", "UP");
        json.set("service", "poco-microservice");

        std::ostream &out = response.send();
        Stringifier::stringify(json, out);
    }
};

// ---------------- Factory ----------------
class HandlerFactory : public HTTPRequestHandlerFactory
{
public:
    HTTPRequestHandler *createRequestHandler(
        const HTTPServerRequest &request) override
    {
        if (request.getURI() == "/api/health")
            return new HealthHandler;

        return nullptr; // 404
    }
};

// ---------------- Application ----------------
class RestServerApp : public ServerApplication
{
protected:
    int main(const std::vector<std::string> &) override
    {
        UInt16 port = 8080;

        HTTPServer server(
            new HandlerFactory,
            ServerSocket(port),
            new HTTPServerParams);

        server.start();
        logger().information("REST server started on port %hu", port);

        waitForTerminationRequest();
        server.stop();

        return Application::EXIT_OK;
    }
};

POCO_SERVER_MAIN(RestServerApp);

