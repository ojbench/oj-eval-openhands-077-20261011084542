cmake_minimum_required(VERSION 3.10)
project(CrossArray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the main source file
set(SOURCES
    main.cpp
)

# Create executable named 'code' as required by OJ
add_executable(code ${SOURCES})

# Set compiler flags
target_compile_options(code PRIVATE -Wall -Wextra -O2)