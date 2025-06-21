cmake_minimum_required(VERSION 3.10)
project(stm32_sim_framework CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)

#add_subdirectory(projects/project_1)
add_subdirectory(projects/project_2)
#add_subdirectory(projects/direct_led)



