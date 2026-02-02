# cmake_minimum_required(VERSION 3.5)
# project(SFMLApp)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(SFML REQUIRED sfml-graphics sfml-window sfml-system)

# add_executable(sfml-app main.cpp)

# target_include_directories(sfml-app PRIVATE ${SFML_INCLUDE_DIRS})
# target_link_libraries(sfml-app ${SFML_LIBRARIES})
# target_compile_options(sfml-app PRIVATE ${SFML_CFLAGS_OTHER})
#########################################################################
cmake_minimum_required(VERSION 4.0)
project(SFMLApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# SFML 2 uses shared libraries by default
set(SFML_STATIC_LIBRARIES OFF)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sfml-app
    main.cpp
)

target_link_libraries(sfml-app
    sfml-graphics
    sfml-window
    sfml-system
)


