cmake_minimum_required(VERSION 3.10)
project(PersonManager)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

include_directories(${SQLite3_INCLUDE_DIRS} include)

add_executable(PersonManager
    src/main.cpp
    src/Database.cpp
    src/Person.cpp
    src/PersonDAO.cpp
    src/Command.cpp
    src/CommandFactory.cpp
)

target_link_libraries(PersonManager ${SQLite3_LIBRARIES})
