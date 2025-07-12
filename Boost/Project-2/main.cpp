#include <boost/filesystem.hpp>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    boost::filesystem::path p = "/home";
    std::cout << "Exists: " << boost::filesystem::exists(p) << "\n";
}
