add_executable(cli_tool main.cpp)

target_include_directories(cli_tool PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(UNIX)
    target_link_libraries(cli_tool dl)
endif()
