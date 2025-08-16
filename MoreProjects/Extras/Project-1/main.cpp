#include <expected>
#include <iostream>

enum class NetworkError
{
    Timeout,
    ConnectionLost,
    UnknownError
};

std::expected<int, NetworkError> fetch_data_from_network()
{
    if (false)
    {
        return std::unexpected(NetworkError::Timeout);
    }

    if (true)
    {
        return std::unexpected(NetworkError::ConnectionLost);
    }

    return 42; // Successfully retrieved value
}

int main()
{

    auto result = fetch_data_from_network();

    if (result)
    {
        std::cout << "Value retrieved: " << *result << '\n';
    }
    else
    {
        std::cout << "Network error: ";

        switch (result.error())
        {
        case NetworkError::Timeout:
            std::cout << "Timeout\n";
            break;
        case NetworkError::ConnectionLost:
            std::cout << "Connection Lost\n";
            break;
        case NetworkError::UnknownError:
            std::cout << "Unknown Error\n";
            break;
        }
    }

    return 0;
}