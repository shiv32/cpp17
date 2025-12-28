cmake_minimum_required(VERSION 3.16)
project(fmt_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE fmt::fmt)
