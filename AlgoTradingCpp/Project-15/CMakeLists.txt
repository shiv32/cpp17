cmake_minimum_required(VERSION 3.10)
project(algoTrade CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Your main source file
add_executable(algoTrade main.cpp)

# RapidJSON is header-only — no linking required
include_directories(/usr/include/rapidjson)

# Optional: Link libcurl if you are using it to fetch HTTP data
find_package(CURL REQUIRED)
target_link_libraries(algoTrade PRIVATE CURL::libcurl)
