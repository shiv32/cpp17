cmake_minimum_required(VERSION 3.14)
project(json_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(json_demo src/main.cpp)

target_link_libraries(json_demo PRIVATE nlohmann_json::nlohmann_json)
