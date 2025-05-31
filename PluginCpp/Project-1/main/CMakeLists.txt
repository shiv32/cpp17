# Create the main executable
add_executable(main_app main.cpp)

# Add include path for PluginInterface
target_include_directories(main_app PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link libdl on Linux/Unix for dynamic loading
if(UNIX)
    target_link_libraries(main_app dl)
endif()
