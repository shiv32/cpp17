#include <iostream>
#include <string>

int main()
{
    std::string filename{R"(\home\shiv/Desktop/project/test.txt)"};

    std::cout << filename << std::endl;

    std::string message{R"MSG(c++ introduced file system API "(in c++17)")MSG"};

    std::cout << message << std::endl;

    return 0;
}