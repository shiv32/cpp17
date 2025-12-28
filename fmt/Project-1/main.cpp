#include <fmt/core.h>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    fmt::print("Hello {}, number = {}\n", "fmt", 42);
}
