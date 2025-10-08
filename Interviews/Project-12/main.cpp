#include <iostream>
#include <fstream>
#include <string>

// RAII class that manages a file resource
class FileRAII
{
    std::ofstream file;

public:
    FileRAII(const std::string &filename)
    {
        file.open(filename);

        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::cout << "File opened: " << filename << "\n";
    }

    void writeLine(const std::string &text)
    {
        file << text << "\n";
    }

    // Automatically releases the resource
    ~FileRAII()
    {
        if (file.is_open())
        {
            file.close();
            std::cout << "File closed automatically.\n";
        }
    }
};

// RAII class managing a dynamic resource
class IntArrayRAII
{
    int *data;
    std::size_t size;

public:
    IntArrayRAII(std::size_t n) : size(n)
    {
        data = new int[size]{};//value-initialize all elements, all initialized to 0.

        std::cout << "Allocated " << size << " integers.\n";
    }

    int &operator[](std::size_t index) 
    { 
        return data[index]; 
    }
    
    ~IntArrayRAII()
    {
        delete[] data;
        std::cout << "Memory freed automatically.\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    try
    {
        // File automatically closed at scope end
        {
            FileRAII file("example.txt");
            file.writeLine("Hello RAII!");
            file.writeLine("This file will be closed automatically.");
        }

        std::cout << "-----------------------------\n";

        // Memory automatically freed at scope end
        {
            IntArrayRAII arr(5);

            for (std::size_t i = 0; i < 5; ++i)
            {
                arr[i] = static_cast<int>(i * 10);
            }

            std::cout << "Array contents: ";

            for (std::size_t i = 0; i < 5; ++i)
            {
                std::cout << arr[i] << " ";
            }
            
            std::cout << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "Program finished.\n";

    return 0;
}
