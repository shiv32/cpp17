#include "Server.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Server server(8080);
    server.start();
    return 0;
}
