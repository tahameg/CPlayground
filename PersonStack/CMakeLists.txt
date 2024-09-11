cmake_minimum_required(VERSION 3.10) # Specify the minimum CMake version required

# Project name and version
project(PersonStack VERSION 1.0)

# Set the build type if not specified (default to Debug)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Set output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

# Define the source and header directories
include_directories(
    ${PROJECT_SOURCE_DIR}/lib/include
    ${PROJECT_SOURCE_DIR}/../DateLib/lib/include
)

# Gather source files
file(GLOB DATE_LIB_SRC ${PROJECT_SOURCE_DIR}/../DateLib/lib/src/*.c)
file(GLOB PERSON_LIB_SRC ${PROJECT_SOURCE_DIR}/lib/src/*.c)

# Add executable
add_executable(PersonStack 
    main.c 
    ${DATE_LIB_SRC}
    ${PERSON_LIB_SRC}
)

# Specify C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set build flags (optional)
if(MSVC)
    target_compile_options(PersonStack PRIVATE /W4)
else()
    target_compile_options(PersonStack PRIVATE -Wall -Wextra -pedantic)
endif()