/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief File IO
 *
        compile and run -->
        g++ -std=c++17 main.cpp -o test -lstdc++fs && ./test && rm test
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

    //-------------------------(Introduction to filesystem library)----------------------------------
    using namespace std::experimental::filesystem;
    path p{R"(/tmp/test.txt)"};

    if (p.has_filename())
    {
        std::cout << p.filename() << std::endl;
    }

    std::cout << "------" << std::endl;

    for (const auto &x : p)
    {
        std::cout << x << std::endl;
    }

    std::cout << "------" << std::endl;

     path p2{R"(/tmp)"};

    directory_iterator beg{p2};
    directory_iterator end{};

    while (beg != end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }
    //---------------------------------------()---------------------------------------------------

    return 0;
}