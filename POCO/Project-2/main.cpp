#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Exception.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace Poco;
using namespace Poco::Net;
using namespace std;

int main()
{
    try
    {
        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        std::cout << "Under Develpoment !" << std::endl;
    }
    catch (Exception &ex)
    {
        cerr << "Exception: " << ex.displayText() << endl;
    }

    return 0;
}
