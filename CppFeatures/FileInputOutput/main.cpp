/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief File IO
 *
        compile and run -->
        g++ -std=c++17 main.cpp -o test -lstdc++fs && ./test && rm test

        Note: dont delete the build directory for this project.
              otherwise current_path() will be set to wrong.
              you can empty it by command
              $rm -rf *
 *
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <fstream>
#include <string>

void Write()
{
    // std::ofstream out{"data.txt"}; //open file using ctor
    // or
    std::ofstream out;
    out.open("data.txt"); // open file using open fun

    out << "Hello world" << std::endl;
    out << 20 << std::endl;
    out.close();
}

void Read()
{
    // std::ifstream input{"data.txt"}; //open file using ctor
    // or
    std::ifstream input;
    input.open("data.txt"); // open file using open fun

    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    input.close();
    std::cout << message << " : " << value << std::endl;
}

void Write2()
{
    // std::ofstream out{"data.txt"}; //open file using ctor
    // or
    std::ofstream out;
    out.open("data.txt"); // open file using open fun

    out << "Hello world" << std::endl;
    out << 20 << std::endl;
    out.close();
}

void Read2()
{
    // std::ifstream input{"data.txt"}; //open file using ctor
    // or
    std::ifstream input;
    input.open("data.txt"); // open file using open fun
    // input.open("dat.txt"); // wrong file name

    // if (!input.is_open())
    // {
    //     std::cout << "Could not open the file" << std::endl;
    //     return;
    // }

    if (input.fail())
    {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    input >> value; // test input.fail(), input.eof()

    // if (input.fail())
    // {
    //     std::cout << "Could not read" << std::endl;
    //     return;
    // }

    if (input.eof())
    {
        std::cout << "End of file encountered" << std::endl;
    }

    if (input.good())
    {
        std::cout << "IO operations are successfull" << std::endl;
    }
    else
    {
        std::cout << "Some IO operations are failed" << std::endl;
    }

    input.setstate(std::ios::failbit);

    if (input.fail())
    {
        std::cout << "fail bit set" << std::endl;
    }

    input.clear(); // it clear all states and set good bit

    if (input.fail())
    {
        std::cout << "fail bit set" << std::endl;
    }
    else
    {
        std::cout << "fail bit clear" << std::endl;
    }

    input.close();
    std::cout << message << " : " << value << std::endl;
}

void Write3()
{
    std::ofstream out{"data.txt"}; // open file using ctor

    if (!out)
    {
        std::cout << "Could not open file for writing" << std::endl;
        return;
    }

    std::string message{"C++ was invented by Bjarne"};

    for (char ch : message)
    {
        out.put(ch);
    }

    out.seekp(5);
    out.put('#');

    out.close();
}

void Read3()
{
    std::ifstream input{"data.txt"}; // open file using ctor

    if (!input)
    {
        std::cout << "Source file not found" << std::endl;
        return;
    }

    std::cout << "Current position is : " << input.tellg() << std::endl;

    // input.seekg(5);

    // std::cout << "Current position is : " << input.tellg() << std::endl;

    // input.seekg(5,std::ios::beg);
    // input.seekg(5,std::ios::cur);
    // input.seekg(5,std::ios::end);
    // input.seekg(-5, std::ios::end);
    // std::cout << "Current position is : " << input.tellg() << std::endl;

    // input.seekg(10, std::ios::beg);
    // std::cout << "Current position is : " << input.tellg() << std::endl;

    char ch{};

    while (input.get(ch))
    {
        std::cout << ch;
    }

    input.close();
}

void UsingFstream()
{
    std::fstream stream{"file.txt"};

    if (!stream)
    {
        std::cout << "File not found. Creating one..." << std::endl;
        std::ofstream out{"file.txt"};
        out.close();
        stream.open("file.txt");
    }

    stream << "Hello shiv !" << std::endl;

    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //-------------(raw string literals c++11)------------------
    /*
     // std::string filename{"\tmp\newfile.txt"};
     //  std::string filename{"\\tmp\\newfile.txt"};
     std::string filename{R"(\tmp\newfile.txt)"};

     std::cout << filename << std::endl;

     // std::string message{R"(C++ introduce filesystem API"(in C++ 17)")"}; //compiler error
     std::string message{R"MSG(C++ introduce filesystem API"(in C++ 17)")MSG"};

     std::cout << message << std::endl;
     */

    //-------------------------(Introduction to filesystem library (C++17) (Deprecated))----------------------------------
    // using namespace std::experimental::filesystem;
    // path p{R"(/tmp/test.txt)"};

    // if (p.has_filename())
    // {
    //     std::cout << p.filename() << std::endl;
    // }

    // std::cout << "------" << std::endl;

    // for (const auto &x : p)
    // {
    //     std::cout << x << std::endl;
    // }

    // std::cout << "------" << std::endl;

    //  path p2{R"(/tmp)"};

    // directory_iterator beg{p2};
    // directory_iterator end{};

    // while (beg != end)
    // {
    //     std::cout << *beg << std::endl;
    //     ++beg;
    // }

    //---------------------------------------(File IO part-1 basics)---------------------------------------------------
    // Write();
    // Read();

    //---------------------------------------(File IO part-2 error handling)--------------------------------------------
    // Write2();
    // Read2();

    //------------------------------(File IO part-3 copy utlility)----------------------------------------------------
    /*

     Note: dont delete the cmake build directory otherwise current_path() will be set to wrong.

    */

    // using namespace std::experimental::filesystem;

    // // std::cout << "current_path() : " << current_path() << std::endl;
    // std::cout << "current_path().parent_path (): " << current_path().parent_path() << std::endl;

    // // path source{R"(/tmp/)"};
    // path source{current_path().parent_path()};

    // // source /= "test.txt";
    // source /= "main.cpp";

    // // path dest{R"(/tmp/)"};
    // path dest{current_path().parent_path()};

    // // dest /= "copy.txt";
    // dest /= "copy.cpp";

    // std::ifstream input{source};

    // if (!input)
    // {
    //     std::cout << "Source file not found !" << std::endl;
    //     return -1;
    // }

    // std::ofstream output{dest};

    // std::string line;

    // while (!std::getline(input, line).eof())
    // {
    //     output << line << std::endl;
    // }

    // input.close();
    // output.close();

    // std::cout << "Copied." << std::endl;

    //-------------------------(File IO part-4 character IO & seeking)-----------------------------
    // Write3();
    // Read3();
    UsingFstream();

    //-------------------------()-----------------------------

    return 0;

    
}