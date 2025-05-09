#include "Server.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>

void handleReceive(int client_fd) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(client_fd, buffer, 1024);
        if (n <= 0) break;
        std::cout << "[Client]: " << buffer << std::endl;
    }
}

Server::Server(int port) : port(port), server_fd(-1) {}

Server::~Server() {
    if (server_fd >= 0) close(server_fd);
}

void Server::start() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    std::cout << "Waiting for connection...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    std::cout << "Client connected!\n";

    std::thread recvThread(handleReceive, client_fd);

    std::string msg;
    while (true) {
        std::getline(std::cin, msg);
        if (msg == "exit") break;
        send(client_fd, msg.c_str(), msg.size(), 0);
    }

    close(client_fd);
    recvThread.join();
}
