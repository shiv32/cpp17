#include <iostream>
#include <fstream>
#include <string>

void write()
{
    std::ofstream out{"test.txt"};

    if (!out)
    {
        std::cout << "could not open file for writing" << std::endl;
        return;
    }

    std::string message{"C++ was invented by bjarne"};

    for (char ch : message)
    {
        out.put(ch);
    }

    out.seekp(5);
    out.put('#');
}

void read()
{
    std::ifstream input{"test.txt"};

    if (!input)
    {
        std::cout << "source file not found" << std::endl;
        return;
    }
   // input.seekg(5);
    //input.seekg(-5, std::ios::end);
   // input.seekg(10, std::ios::beg);
    std::cout << "Current position : " << input.tellg() << std::endl;

    char ch{};

    while (input.get(ch))
    {
        std::cout << ch;
    }

    std::cout << std::endl;
}

void UsingFstream()
{

std::fstream stream{"file.txt"};

if(!stream)
{
    std::cout<<"file dosnt exist creating one......"<<std::endl;
std::ofstream out{"file.txt"};
out.close();
stream.open("file.txt");
}

stream<<"hello world"<<std::endl;

stream.seekg(0);
std::string line;
std::getline(stream,line);
std::cout<<line<<std::endl;

}


int main()
{
    //write();
    //read();
    UsingFstream();

    return 0;
}