cmake_minimum_required(VERSION 3.16)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)


project(task_rest
    VERSION 1.0
    DESCRIPTION "C++17 REST Mini Project with Catch2 Tests"
    LANGUAGES CXX
)

# ---------------- C++ Standard ----------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------- Build Type ----------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# ---------------- FetchContent ----------------
include(FetchContent)

# ---- nlohmann/json ----
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)

# ---- cpp-httplib ----
FetchContent_Declare(
    httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.15.3
)

# ---- Catch2 ----
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(
    nlohmann_json
    httplib
    Catch2
)

# ---------------- Server ----------------
add_executable(task_rest
    main.cpp
)

target_link_libraries(task_rest
    PRIVATE
        nlohmann_json::nlohmann_json
        httplib::httplib
        pthread
)

# ---------------- Testing ----------------
include(CTest)
enable_testing()

add_executable(task_rest_tests
    tests/api_tests.cpp
)

target_link_libraries(task_rest_tests
    PRIVATE
        Catch2::Catch2WithMain
        nlohmann_json::nlohmann_json
        httplib::httplib
        pthread
)

add_test(
    NAME TaskRestApiTests
    COMMAND task_rest_tests
)

# ---------------- Warnings (Optional but Pro) ----------------
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(task_rest PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(task_rest_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ---------------- Summary ----------------
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
