#include <fstream>
#include <iostream>
#include <string>

void writeFile(const std::string &file, const std::string &data)
{
    std::ofstream out(file); // TEXT MODE
    out << data << '\n';
}

std::string readFile(const std::string &file)
{
    std::ifstream in(file); // TEXT MODE
    std::string data;
    std::getline(in, data);
    return data;
}

int main()
{
    writeFile("data.txt", "Hello C++");
    std::cout << readFile("data.txt") << '\n';
}
