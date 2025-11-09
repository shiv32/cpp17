#include <iostream>
#include <stdexcept>
#include <string>

//Modern Style

class NetworkError : public std::runtime_error
{
public:
    /*
      “Inheriting Constructors”
      Inside a derived class to automatically inherit all constructors from the base class.
    */
    using std::runtime_error::runtime_error;
};

class ConnectionError : public NetworkError
{
public:
    using NetworkError::NetworkError;
};

class SendError : public NetworkError
{
public:
    using NetworkError::NetworkError;
};

void connectToServer(bool success)
{
    if (!success)
        throw ConnectionError("Failed to connect to server");

    std::cout << "Connected successfully.\n";
}

void sendData(bool success)
{
    if (!success)
        throw SendError("Failed to send data to server");

    std::cout << "Data sent successfully.\n";
}

int main()
{
    try
    {
        connectToServer(false); // will throw ConnectionError
        sendData(true);

        // connectToServer(true);
        // sendData(false); // will throw data Error
    }
    catch (const NetworkError &e)
    {
        std::cerr << "NetworkError: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Other error: " << e.what() << '\n';
    }

    return 0;
}
