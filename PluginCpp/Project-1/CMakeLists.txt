cmake_minimum_required(VERSION 3.10)
project(PluginDemo)

set(CMAKE_CXX_STANDARD 17)

# Add include directory for interfaces
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(main)
add_subdirectory(plugins)
