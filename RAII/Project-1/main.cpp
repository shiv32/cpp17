/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief RAII with File Handling
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <string>

class FileRAII
{
private:
    std::ofstream file;

public:
    // Constructor: Opens the file
    FileRAII(const std::string &filename)
    {
        file.open(filename);
        
        if (!file)
        {
            throw std::runtime_error("Failed to open file");
        }
    }

    // Write to the file
    void write(const std::string &text)
    {
        file << text << std::endl;
    }

    // Destructor: Closes the file automatically
    ~FileRAII()
    {
        if (file.is_open())
        {
            file.close();
            std::cout << "File closed in destructor.\n";
        }
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    try
    {
        FileRAII myFile("example.txt");
        myFile.write("Hello, RAII!");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}