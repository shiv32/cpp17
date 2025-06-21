file(GLOB_RECURSE HAL_SRC hal/*.cpp)
file(GLOB_RECURSE APP_SRC app/*.cpp)

add_library(sim_hal ${HAL_SRC} ${APP_SRC}) #static lib .a by default
