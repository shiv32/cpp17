/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //-------------(raw string literals c++11)------------------

    // std::string filename{"\tmp\newfile.txt"};
    //  std::string filename{"\\tmp\\newfile.txt"};
    std::string filename{R"(\tmp\newfile.txt)"};

    std::cout << filename << std::endl;

    // std::string message{R"(C++ introduce filesystem API"(in C++ 17)")"}; //compiler error
    std::string message{R"MSG(C++ introduce filesystem API"(in C++ 17)")MSG"};

    std::cout << message << std::endl;

    //-------------------------()----------------------------------

    return 0;
}