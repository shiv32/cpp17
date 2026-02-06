#include <fstream>
#include <iostream>
#include <string>

void writeFile(const std::string &file, const std::string &data)
{
    std::ofstream out(file, std::ios::binary); // CHANGE #1
    size_t len = data.size();                  // CHANGE #2
    out.write(reinterpret_cast<const char *>(&len), sizeof(len));
    out.write(data.data(), len); // CHANGE #3
}

std::string readFile(const std::string &file)
{
    std::ifstream in(file, std::ios::binary); // CHANGE #1
    size_t len;
    in.read(reinterpret_cast<char *>(&len), sizeof(len));
    std::string data(len, '\0'); // CHANGE #4
    in.read(&data[0], len);
    return data;
}

int main()
{
    writeFile("data.bin", "Hello C++");
    std::cout << readFile("data.bin") << '\n';
}
