cmake_minimum_required(VERSION 3.10)
project(AVR_Project LANGUAGES CXX)

# Define MCU and CPU frequency
set(MCU atmega328p)
set(FREQ 16000000UL)

# Compiler options
set(COMPILE_OPTIONS 
    -mmcu=${MCU} 
    -DF_CPU=${FREQ} 
    -Os 
    -std=c++17
    -Wall 
    -Wextra 
    -ffunction-sections 
    -fdata-sections 
    -fno-exceptions 
    -fno-rtti
)


# Set compilers
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_COMPILER avr-gcc)

# Define executable
add_executable(main.elf main.cpp)

# Apply compile options
target_compile_options(main.elf PRIVATE ${COMPILE_OPTIONS})

# Force correct linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU} -Wl,--gc-sections")

# Generate HEX file
add_custom_command(TARGET main.elf POST_BUILD
    COMMAND avr-objcopy -O ihex main.elf main.hex
    COMMENT "Generating HEX file..."
)
