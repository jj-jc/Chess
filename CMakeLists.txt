cmake_minimum_required(VERSION 3.12)

project(ChessGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES
    "src/*.cpp"
    "lib/*.cpp"
    )

# Create executable
add_executable(ChessGame ${SOURCES})

# Include directories
target_include_directories(ChessGame PRIVATE src lib)

find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

# Find GLUT library (dev package not needed; we bundle our own glut.h)
find_library(GLUT_LIBRARY NAMES glut PATHS /usr/lib/x86_64-linux-gnu /usr/lib64 /usr/lib)
if(NOT GLUT_LIBRARY)
    set(GLUT_LIBRARY "/usr/lib/x86_64-linux-gnu/libglut.so.3.12.0")
    message(STATUS "Using GLUT library: ${GLUT_LIBRARY}")
endif()

target_link_libraries(ChessGame
    ${OPENGL_LIBRARIES}
    ${OPENGL_GLU_LIBRARIES}
    Freetype::Freetype
    ${GLUT_LIBRARY}
)