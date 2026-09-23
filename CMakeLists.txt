cmake_minimum_required(VERSION 3.20)

project(software_renderer
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

add_executable(software_renderer 
    src/main.cpp 
    src/FrameBuffer.cpp
)

target_link_libraries(software_renderer
    PRIVATE SDL3::SDL3
)