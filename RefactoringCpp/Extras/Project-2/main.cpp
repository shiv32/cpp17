#include <iostream>
#include <stdexcept>
#include <string>

class ConnectionError : public std::runtime_error
{
public:
    explicit ConnectionError(const std::string &message)
        : std::runtime_error(message) {}
};

class SendError : public std::runtime_error
{
public:
    explicit SendError(const std::string &message)
        : std::runtime_error(message) {}
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
    catch (const ConnectionError &e)
    {
        std::cerr << "Connection error: " << e.what() << '\n';
    }
    catch (const SendError &e)
    {
        std::cerr << "Send error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Other error: " << e.what() << '\n';
    }

    return 0;
}
