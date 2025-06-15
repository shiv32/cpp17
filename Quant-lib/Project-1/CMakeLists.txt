cmake_minimum_required(VERSION 3.10)
project(QuantLibTest)

set(CMAKE_CXX_STANDARD 17)

find_package(QuantLib REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test QuantLib)

#Add RPATH so your binary knows where to find libQuantLib.so
set_target_properties(test PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "/usr/local/lib"
)
