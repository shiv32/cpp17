// Compile with: g++ -std=c++17 -o poco_client poco_client.cpp -lPocoNet -lPocoFoundation

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <sstream>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

// Observer interface
class IResponseObserver
{
public:
    virtual void onResponse(const string &response) = 0;
};

// Subject class (Observable)
class ResponseNotifier
{
    vector<IResponseObserver *> observers;

public:
    void addObserver(IResponseObserver *obs)
    {
        observers.push_back(obs);
    }
    void notify(const string &response)
    {
        for (auto *obs : observers)
        {
            obs->onResponse(response);
        }
    }
};

// Command interface
class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
};

// Singleton HTTP Client Manager
class HttpClientManager
{
private:
    HttpClientManager() = default;

public:
    HttpClientManager(const HttpClientManager &) = delete;
    HttpClientManager &operator=(const HttpClientManager &) = delete;

    static HttpClientManager &getInstance()
    {
        static HttpClientManager instance;
        return instance;
    }

    HTTPClientSession createSession(const URI &uri)
    {
        return HTTPClientSession(uri.getHost(), uri.getPort());
    }
};

// Factory for creating HTTP Requests
class HttpRequestFactory
{
public:
    static unique_ptr<HTTPRequest> createRequest(const string &method, const URI &uri)
    {
        return make_unique<HTTPRequest>(method, uri.getPathEtc(), HTTPMessage::HTTP_1_1);
    }
};

// Concrete Command for HTTP GET Request
class HttpGetCommand : public ICommand
{
    URI uri;
    ResponseNotifier &notifier;

public:
    HttpGetCommand(const string &url, ResponseNotifier &n) : uri(url), notifier(n) {}

    void execute() override
    {
        try
        {
            auto &client = HttpClientManager::getInstance();
            HTTPClientSession session = client.createSession(uri);

            auto request = HttpRequestFactory::createRequest(HTTPRequest::HTTP_GET, uri);
            session.sendRequest(*request);

            HTTPResponse response;
            istream &rs = session.receiveResponse(response);

            stringstream ss;
            StreamCopier::copyStream(rs, ss);

            notifier.notify(ss.str());
        }
        catch (const Exception &ex)
        {
            notifier.notify(string("Error: ") + ex.displayText());
        }
    }
};

// Concrete Observer that prints the response
class ConsoleResponseObserver : public IResponseObserver
{
public:
    void onResponse(const string &response) override
    {
        cout << "Response received:\n"
             << response << "\n";
    }
};

// Main entry point
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    cout << "POCO HTTP Client with Design Patterns - Mini Project\n";

    ResponseNotifier notifier;
    ConsoleResponseObserver consoleObserver;

    notifier.addObserver(&consoleObserver);

    string url = "http://httpbin.org/get";

    HttpGetCommand getCmd(url, notifier);

    getCmd.execute();

    return 0;
}
