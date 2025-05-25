cmake_minimum_required(VERSION 3.10)
project(PocoSQLiteCRUD)

find_package(Poco REQUIRED COMPONENTS Data DataSQLite Foundation)

add_executable(poco_sqlite_crud main.cpp)

target_link_libraries(poco_sqlite_crud Poco::Data Poco::DataSQLite Poco::Foundation)
set_target_properties(poco_sqlite_crud PROPERTIES CXX_STANDARD 17)
