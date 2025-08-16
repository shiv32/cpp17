#include <iostream>
#include <unistd.h>

int main()
{
    std::string name = getlogin();

    std::clog << name << std::endl;

    return 0;
}