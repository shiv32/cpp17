/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief A simple program to test the C++ POCO installation: HTTP Client
 
    g++ -o http_client main.cpp -lPocoFoundation -lPocoNet -lPocoUtil && ./http_client && rm http_client

 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <iostream>
#include <sstream>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main()
{
    try
    {
        HTTPClientSession session("www.google.com");
        HTTPRequest request(HTTPRequest::HTTP_GET, "/");
        session.sendRequest(request);

        HTTPResponse response;
        istream &responseStream = session.receiveResponse(response);

        cout << "Response: " << response.getStatus() << " " << response.getReason() << endl;

        // StreamCopier::copyStream(responseStream, cout);
    }
    catch (const Exception &ex)
    {
        cerr << "Exception: " << ex.displayText() << endl;
    }

    return 0;
}
