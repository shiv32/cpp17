/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Test-2

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
// #include <iostream>
// #include <string>
// #include <vector>

 //using namespace Poco::Data;

 /**

[build] /usr/include/Poco/Data/Statement.h:484:22: note:                 void Poco::Data::Keywords::vector(Poco::Data::Statement&)
[build]  inline void Data_API vector(Statement& statement)
  * 
  */
using namespace Poco::Data::Keywords;

//build] /home/shiv/Desktop/desktop_files/1/projects/c++17/thread/cpp17/Practice/Test-2/main.cpp:40:6: error: reference to ‘vector’ is ambiguous
using namespace std;


int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

     std::vector<int> iVect{};
     //vector<int> iVect{};

    return 0;
}