cmake_minimum_required(VERSION 3.10)
project(BlockchainExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add executable
add_executable(blockchain main.cpp)

# Link OpenSSL
target_link_libraries(blockchain OpenSSL::SSL OpenSSL::Crypto)
