cmake_minimum_required(VERSION 4.0)
project(poco_rest)

set(CMAKE_CXX_STANDARD 17)

find_package(Poco REQUIRED Net Util JSON)

add_executable(rest_server main2.cpp)
target_link_libraries(rest_server Poco::Net Poco::Util Poco::JSON)
