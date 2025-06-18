cmake_minimum_required(VERSION 3.10)
project(PDFiumApp)

set(CMAKE_CXX_STANDARD 17)

# Add the PDFium headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable
add_executable(pdfium_test main2.cpp)

# Link with libpdfium.so
target_link_libraries(pdfium_test ${CMAKE_SOURCE_DIR}/lib/libpdfium.so)
