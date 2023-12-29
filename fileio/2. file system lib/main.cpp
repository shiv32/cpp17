/*
g++ -std=c++17 main.cpp -o test -lstdc++fs
ref: https://stackoverflow.com/questions/33149878/experimentalfilesystem-linker-error
*/

#include <iostream>
#include <experimental/filesystem>

using namespace std::experimental::filesystem;

int main()
{

    path p{R"(/home/shiv/Desktop/project/)"};

    // if (p.has_filename())
    // {
    //     std::cout << p.filename() << std::endl;
    // }

    // for (const auto &x : p)
    // {
    //     std::cout << x << std::endl;
    // }

    directory_iterator beg{p};
    directory_iterator end{};

    while (beg != end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }

    return 0;
}