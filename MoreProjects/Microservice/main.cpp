#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

// Handler for /hello
class HelloRequestHandler : public HTTPRequestHandler {
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override {
        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("application/json");

        ostream& out = response.send();
        out << R"({"message": "Hello from C++ microservice!"})";
    }
};

// Factory to route requests
class RequestHandlerFactory : public HTTPRequestHandlerFactory {
public:
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override {
        if (request.getURI() == "/hello") {
            return new HelloRequestHandler;
        }
        return nullptr; // 404 for others
    }
};

// Main microservice app
class MicroserviceApp : public ServerApplication {
protected:
    int main(const vector<string>& args) override {
        ServerSocket svs(9090); // listen on port 9090
        HTTPServer srv(new RequestHandlerFactory, svs, new HTTPServerParams);

        srv.start();
        cout << "C++ Microservice started at http://localhost:9090/hello\n";
        waitForTerminationRequest(); // Ctrl+C to stop
        srv.stop();

        return Application::EXIT_OK;
    }
};

int main(int argc, char** argv) {
    MicroserviceApp app;
    return app.run(argc, argv);
}
