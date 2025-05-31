# Default plugin
add_library(default_plugin SHARED DefaultPlugin.cpp)
target_include_directories(default_plugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(default_plugin PROPERTIES OUTPUT_NAME "default_plugin")

# Extra plugin (optional)
add_library(extra_plugin SHARED ExtraPlugin.cpp)
target_include_directories(extra_plugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(extra_plugin PROPERTIES OUTPUT_NAME "extra_plugin")


# New plugin
add_library(new_plugin SHARED NewPlugin.cpp)
target_include_directories(new_plugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(new_plugin PROPERTIES OUTPUT_NAME "new_plugin")
