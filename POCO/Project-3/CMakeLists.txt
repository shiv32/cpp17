cmake_minimum_required(VERSION 3.10)
project(PocoHttpClientDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Poco REQUIRED COMPONENTS Net Foundation)

add_executable(poco_client main.cpp)

target_link_libraries(poco_client PRIVATE Poco::Net Poco::Foundation)
