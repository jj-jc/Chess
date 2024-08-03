cmake_minimum_required(VERSION 3.12)

project(ChessGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES
    "src/*.cpp"
    "src/*.h"
    )

# Create executable
add_executable(ChessGame ${SOURCES})

# Include directories
target_include_directories(ChessGame PRIVATE src lib)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)