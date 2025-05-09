#pragma once
#include <string>

class Client {
private:
    std::string ip;
    int port;
    int sock;

public:
    Client(const std::string& ip, int port);
    ~Client();
    void run();
};
