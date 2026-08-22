cmake_minimum_required(VERSION 3.10)
project(OpenGLThing)

set(CMAKE_CXX_STANDARD 20)

# Include paths
include_directories(include)
include_directories("/usr/include")

# Sources: main.cpp and glad.c
add_executable(OpenGLThing
        src/main.cpp
        src/glad.c
)

# Find system OpenGL
find_package(OpenGL REQUIRED)
