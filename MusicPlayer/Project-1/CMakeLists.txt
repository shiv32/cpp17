cmake_minimum_required(VERSION 3.5)
project(SFMLApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-audio)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(sfml-app main.cpp)

target_include_directories(sfml-app PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(sfml-app ${SFML_LIBRARIES})
target_compile_options(sfml-app PRIVATE ${SFML_CFLAGS_OTHER})
