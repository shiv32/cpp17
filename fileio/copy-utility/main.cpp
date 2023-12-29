/*

g++ main.cpp -o test -lstdc++fs

*/

#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

int main()
{
    using namespace std::experimental::filesystem;

    path source{current_path()};

    source /= "main.cpp";

    path dest{current_path()};

    dest /= "copy.cpp";

    std::ifstream input{source};

    if (!input)
    {
        std::cout << "source file not found" << std::endl;
        return -1;
    }

    std::ofstream output{dest};

    std::string line;

    while (!std::getline(input, line).eof())
    {

        output << line << std::endl;
    }

    input.close();
    output.close();

    return 0;
}
