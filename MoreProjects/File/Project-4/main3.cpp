#include <iostream>
#include <fstream>
#include <string>

// -------- TEXT FILE --------
void writeTextFile(const std::string &file)
{
    std::ofstream out(file);
    if (!out)
    {
        std::cerr << "Text file write failed\n";
        return;
    }

    std::string msg = "Hello C++17 File IO";
    out << msg << '\n';
}

void readTextFile(const std::string &file)
{
    std::ifstream in(file);
    if (!in)
    {
        std::cerr << "Text file read failed\n";
        return;
    }

    std::string msg;
    std::getline(in, msg);
    std::cout << "Text read: " << msg << '\n';
}

// -------- BINARY FILE --------
void writeBinaryFile(const std::string &file)
{
    std::ofstream out(file, std::ios::binary);
    if (!out)
    {
        std::cerr << "Binary file write failed\n";
        return;
    }

    std::string msg = "Hello C++17 File IO";

    std::size_t len = msg.size();
    out.write(reinterpret_cast<const char *>(&len), sizeof(len));
    out.write(msg.data(), len);
}

void readBinaryFile(const std::string &file)
{
    std::ifstream in(file, std::ios::binary);
    if (!in)
    {
        std::cerr << "Binary file read failed\n";
        return;
    }

    std::size_t len;
    in.read(reinterpret_cast<char *>(&len), sizeof(len));

    std::string msg(len, '\0');
    in.read(&msg[0], len);

    std::cout << "Binary read: " << msg << '\n';
}

// -------- MAIN --------
int main()
{
    writeTextFile("data.txt");
    readTextFile("data.txt");

    writeBinaryFile("data.bin");
    readBinaryFile("data.bin");

    return 0;
}
