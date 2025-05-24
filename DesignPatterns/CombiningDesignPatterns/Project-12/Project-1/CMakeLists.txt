cmake_minimum_required(VERSION 3.8)
project(DataExporterApp)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(DataExporterApp
    main.cpp
    src/Exporter.cpp
    src/CSVExporter.cpp
    src/JSONExporter.cpp
    src/XMLExporter.cpp
    src/ExporterFactory.cpp
    src/Logger.cpp
)
