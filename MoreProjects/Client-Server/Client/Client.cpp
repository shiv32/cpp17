#include "Client.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

void handleReceive(int sock) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(sock, buffer, 1024);
        if (n <= 0) break;
        std::cout << "[Server]: " << buffer << std::endl;
    }
}

Client::Client(const std::string& ip, int port) : ip(ip), port(port), sock(-1) {}

Client::~Client() {
    if (sock >= 0) close(sock);
}

void Client::run() {
    sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr);

    connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr));
    std::cout << "Connected to server!\n";

    std::thread recvThread(handleReceive, sock);

    std::string msg;
    while (true) {
        std::getline(std::cin, msg);
        if (msg == "exit") break;
        send(sock, msg.c_str(), msg.size(), 0);
    }

    close(sock);
    recvThread.join();
}
