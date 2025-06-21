#pragma once
#include <iostream>
#include <string>

class UART
{
public:
    void send(const std::string &msg)
    {
        std::cout << "[MOCK UART] Sending: " << msg << "\n";
    }

    std::string receive()
    {
        std::string input = "MockedData";
        std::cout << "[MOCK UART] Receiving: " << input << "\n";
        return input;
    }
};
