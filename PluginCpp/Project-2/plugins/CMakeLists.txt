# Convert plugin
add_library(convert SHARED ConvertPlugin.cpp)
target_include_directories(convert PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(convert PROPERTIES OUTPUT_NAME "convert")

# Export plugin
add_library(export SHARED ExportPlugin.cpp)
target_include_directories(export PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(export PROPERTIES OUTPUT_NAME "export")

# Info plugin
add_library(info SHARED InfoPlugin.cpp)
target_include_directories(info PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(info PROPERTIES OUTPUT_NAME "info")

