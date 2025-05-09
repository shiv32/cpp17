#include "Client.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Client client("127.0.0.1", 8080);
    client.run();
    return 0;
}
