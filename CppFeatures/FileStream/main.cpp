#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::ofstream outFile("test.txt", std::ios_base::trunc);

    if (!outFile.good())
    {
        std::cerr << "Error while opening output file!" << std::endl;
        return -1;
    }

    outFile << "There were " << argc << " arguments to this program." << std::endl;
    outFile << "They are: " << std::endl;

    for (int i = 0; i < argc; i++)
    {
        outFile << argv[i] << std::endl;
    }

    return 0;
}
