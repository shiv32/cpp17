cmake_minimum_required(VERSION 3.11)
project(MyCliApp VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch CLI11
include(FetchContent)
FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(CLI11)

# Add your executable
add_executable(MyCliApp src/main.cpp)

# Link CLI11 to your executable
target_link_libraries(MyCliApp PRIVATE CLI11::CLI11)
