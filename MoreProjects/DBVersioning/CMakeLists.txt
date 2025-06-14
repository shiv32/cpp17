cmake_minimum_required(VERSION 3.10)
project(DBMigrator)

set(CMAKE_CXX_STANDARD 17)

add_executable(DBMigrator main.cpp db_migrator.cpp)
find_package(SQLite3 REQUIRED)
target_link_libraries(DBMigrator SQLite::SQLite3)
