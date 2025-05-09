#pragma once
#include <string>

class Server {
private:
    int port;
    int server_fd;
public:
    explicit Server(int port);
    ~Server();
    void start();
};
