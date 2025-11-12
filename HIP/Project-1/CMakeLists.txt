cmake_minimum_required(VERSION 3.21)

# Set HIP paths BEFORE project()
set(CMAKE_PREFIX_PATH /opt/rocm/lib/cmake /opt/rocm)
list(APPEND CMAKE_MODULE_PATH /opt/rocm/lib/cmake/hip)

project(HIP_HelloWorld LANGUAGES HIP CXX)

# Find HIP package
find_package(hip REQUIRED CONFIG)

# Set C++ and HIP standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_HIP_STANDARD 17)
set(CMAKE_HIP_STANDARD_REQUIRED ON)

# Set target architecture to ONLY gfx803 (your RX 580)
# This avoids compiling for multiple architectures
set(GPU_TARGETS "gfx803")
set(CMAKE_HIP_FLAGS "${CMAKE_HIP_FLAGS} --offload-arch=${GPU_TARGETS}")

# Add executables
add_executable(hello_gpu src/hello_gpu.hip)
add_executable(gpu_check src/gpu_check.hip)
add_executable(arch_check src/arch_check.hip)

# Link HIP libraries
target_link_libraries(hello_gpu PRIVATE hip::host)
target_link_libraries(gpu_check PRIVATE hip::host)
target_link_libraries(arch_check PRIVATE hip::host)
